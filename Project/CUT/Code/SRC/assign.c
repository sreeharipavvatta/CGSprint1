/*
FILE NAME: assign.c

DESCRIPTION: For each valid defect it searches for programmers if found assigns that defect to them.
*/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include "../Header/fun_head.h"
#define SUCCESS 1
#define ERROR 0
#define MAXDEFECT 10
#define MAXSTRLEN 200
#define MAXEMP 10
extern pthread_mutex_t lock;
int getEmployee(Emp *arr[])
{
    char *f_loc = "../data/employees.txt"; // Location of Employee Database

    FILE *fpr = fopen(f_loc, "r");
    if (fpr == NULL)
    {
        printf("\n--- Unable to read Employee file ---\n");
        exit(1);
    }

    char str[MAXSTRLEN + 1];
    int i = 0;
    while (1)
    {
        if (fgets(str, MAXSTRLEN, fpr) == NULL)
        {
            break;
        }

        arr[i] = (Emp *)calloc(1, sizeof(Emp));

        char *newstr = (char *)calloc(strlen(str), sizeof(char));
        strcpy(newstr, str);
        char *token = strtok(newstr, ":");
        arr[i]->Id = (char *)calloc(strlen(token), sizeof(char));
        arr[i]->Id = token;
        token = strtok(NULL, ":");
        arr[i]->Name = (char *)calloc(strlen(token), sizeof(char));
        arr[i]->Name = token;
        token = strtok(NULL, ":");
        arr[i]->BUnit = (char *)calloc(strlen(token), sizeof(char));
        arr[i]->BUnit = token;
        token = strtok(NULL, ":");
        arr[i]->Expertise = (char *)calloc(strlen(token), sizeof(char));
        arr[i]->Expertise = token;
        token = strtok(NULL, ":");
        arr[i]->Designation = (char *)calloc(strlen(token), sizeof(char));
        arr[i]->Designation = token;
        arr[i]->n_defect = 0;
        arr[i]->assigned_arr[MAXDEFECT] = (defect *)calloc(5, sizeof(defect));
        i++;
    }

    return i;
}
void displayEmployees(Emp *arr[], int n_emp)
{
    for (int i = 0; i < n_emp; i++)
    {
        printf("\nID: %s Name: %s", arr[i]->Id, arr[i]->Name);
    }
}
void unassignedDefect(defect *defectptr)
{
    char *fileDefectPtr = "../data/out/unassignedDefect.txt";
	FILE *flp;
	flp = fopen(fileDefectPtr, "a");
	 if (flp == NULL)
    {
       printf("Issue in opening the input file");
	   return ERROR;
    }
	fprintf(flp,  "%s : %s : %s : %s : %s : %s : %s\n", defectptr->defectID,
                                                        defectptr->description,
                                                        defectptr->moduleName,
                                                        defectptr->functionalArea,
                                                        defectptr->date,
                                                        defectptr->status,
                                                        defectptr->type);
	fclose(flp);
 
}
void searchProgrammer(defect *defectptr, Emp *arr[], int n_emp)
{
    int i = 0, foundflag = 0;
    for (i = 0; i < n_emp; i++)
    {
        if (strcmp(defectptr->functionalArea, arr[i]->Expertise) == 0)
        {
            foundflag = 1;
            defectptr->status = "Assigned";
            arr[i]->n_defect++;
            arr[i]->assigned_arr[(arr[i]->n_defect) - 1] = defectptr;
            break;
        }
    }
    if (foundflag == 0)
    {
        printf("\n--- Programmer not found for defect Id: %s ---", defectptr->defectID);
        unassignedDefect(defectptr);
        return;
    }
    else
    {
        printf("\nDefect Id: %s\nStatus: %s\n", defectptr->defectID, defectptr->status);
        printf("Module Name: %s\nFunctional Area: %s\nDescription: %s\n\nHas been assigned to:-\nEmployee Id: %s\nEmployee Name: %s\n", defectptr->moduleName, defectptr->functionalArea, defectptr->description, arr[i]->Id, arr[i]->Name);
    }
}
void createEmployeeFile(Emp *arr[], int n_emp)
{
    char out_file[MAXSTRLEN];
    for (int i = 0; i < n_emp; i++)
    {
        if (arr[i]->n_defect > 0)
        {
            sprintf(out_file, "../data/out/%s_assignments.txt", arr[i]->Id);
            FILE *fp = fopen(out_file, "a");
            if (fp == NULL)
            {
                printf("\n--- Unable to write into output Employee file ---\n");
                pthread_exit(NULL);
            }
            for (int j = 0; j < arr[i]->n_defect; j++)
            {
                fprintf(fp, "%s : %s : %s : %s : %s : %s : %s : %s", arr[i]->Id, arr[i]->Name, arr[i]->assigned_arr[j]->defectID, arr[i]->assigned_arr[j]->description, arr[i]->assigned_arr[j]->moduleName, arr[i]->assigned_arr[j]->functionalArea, arr[i]->assigned_arr[j]->date, arr[i]->assigned_arr[j]->type);
            }
            fclose(fp);
        }
    }
}
void assignEmployee(defect *arr[], int vdc)
{
    Emp *emp_arr[MAXEMP];             // Array of Employee structure
    int n_emp = getEmployee(emp_arr); // n_emp: No of employees in database

    printf("\n\n--- Total Employee: %d ---\n", n_emp);
    displayEmployees(emp_arr, n_emp);

    int odc = 0; // odc: Open Defects Count
    for (int i = 0; i < vdc; i++)
    {
        if (!strcmp(arr[i]->status, "open"))
        {
            odc++;
            printf("\n\n--- Searching Programmer for defect Id: %s ---", arr[i]->defectID);
            searchProgrammer(arr[i], emp_arr, n_emp);
        }
    }
    // printf("\n--- Total Open Defects %d ---\n", odc);
    createEmployeeFile(emp_arr, n_emp);

    for (int i = 0; i < odc; i++)
    {
        free(emp_arr[i]);
    }
}