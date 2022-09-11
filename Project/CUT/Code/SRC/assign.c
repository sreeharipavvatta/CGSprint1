/*
Filename: assign.c
Description: Assigns defects to programmers
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
      /*
    arr[] is array of Employee Structure
    Create File Pointer to open employee.txt
    Display proper error if file cannot be opened anyhow.

    Tokenise each line of file and store information inside arr[]

    While storing insitialise Employee->n_defect =0;
    */
    char *f_loc = "../data/employee.txt"; // Location of Employee Database


    FILE *fpr = fopen(f_loc, "a");
            if (fpr == NULL)
            {
                printf("\n--- Unable to write into output Employee file ---\n");
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
       
    //    EmpID:Emp Name:Business Unit:ManageID,Functional area of expertise:
        //    Designation
            arr[i] = (Emp *)calloc(1, sizeof(Emp));
               
            char *newstr = (char *)calloc(strlen(str), sizeof(char));
            strcpy(newstr, str);
            char *token = strtok(newstr, ":");
            arr[i]->ID = (char *)calloc(strlen(token), sizeof(char));
            arr[i]->ID = token;
            token = strtok(NULL, ":");
            arr[i]->Name = (char *)calloc(strlen(token), sizeof(char));
            arr[i]->Name = token;
            token = strtok(NULL, ":");
            arr[i]->Business Unit = (char *)calloc(strlen(token), sizeof(char));
            arr[i]->Business Unit = token;
            token = strtok(NULL, ":");
            arr[i]->ManageID = (char *)calloc(strlen(token), sizeof(char));
            arr[i]->ManageID = token;
            token = strtok(NULL, ":");
            arr[i]->Functional area of expertise = (char *)calloc(strlen(token), sizeof(char));
            arr[i]->Functional area of expertise = token;
            token = strtok(NULL, ":");
            arr[i]->Designation = (char *)calloc(strlen(token), sizeof(char));
            arr[i]->Designation = token;
            arr[i]->n_defect = (char *)calloc(strlen(MAXDEFECT), sizeof(char));
            arr[i]->n_defect = 0;
            i++;
    }
   
   
    
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
    /*
    defectptr contains structure of defect
    Append whole information into a file "unassignedDefect.txt"
    Create file if not present inside Project/CUT/Code/data/

    Also display proper message on the terminal

    */
}
void searchProgrammer(defect *defectptr, Emp *arr[])
{
    /*defectptr is structure of defect with status open
    arr[] is array of Employee Structure

    For incoming defectptr loop on arr[],
    search for employee with same functional area
    {Employee is arr[index], index at which search is successfull}

    If found, change status of defect to assigned, increase Employee->n_defect
    and put whole assigned defect structure inside Employee->assigned_arr[n-defect-1]

    At the end, defects assigned to programmers to be displayed along with defect description,
    module name, functional area, filed-on date type, Emp ID and EMP Name on the terminal.

    If not found call unassignedDefect Function

    */
    printf("\nID: %s Status: %s", defectptr->defectID, defectptr->status);
}
void createEmployeeFile(Emp *arr[], int n_emp)
{
    /*
    arr[] is array of Employee Structure
    Loop on arr, if at some index arr[index]->n_defect >0
    Which means there is some defect assigned to the employee

    Create a file with name <arr[index]->Id>_assignments.txt

    Put following information inside the file in one line for each assignment.
    defects ID, defect description, module name, functional area,
    filed-on date, type, Emp ID and EMP Name.


    */
    char out_file[MAXSTRLEN];
    for (int i = 0; i < n_emp; i++)
    {
        if (arr[i]->n_defect > 0)
        {
            sprintf(out_file, "../data/%s_assignments.txt", arr[i]->Id);
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

    printf("\n\n--- Total Employee: %d ---\n\n", n_emp);
    displayEmployees(emp_arr, n_emp);

    /*
    Loop on defect arr
    If defect status = open
    send that defect to searchProgrammer fn
    */
    int odc = 0; // odc: Open Defects Count
    for (int i = 0; i < vdc; i++)
    {
        if (!strcmp(arr[i]->status, "open"))
        {
            odc++;
            searchProgrammer(arr[i], emp_arr);
        }
    }
    printf("\n--- Total Open Defects %d ---\n", odc);

    // displayvalidDefects(arr, vdc);
}