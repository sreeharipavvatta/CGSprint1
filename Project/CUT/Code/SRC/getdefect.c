/*
Filename: getdefect.c
Description: Read all defects from input file.
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
extern pthread_mutex_t lock;
int checkValidity(char *str)
{
    int count = 0;
    char *s = (char *)calloc(strlen(str), sizeof(char));
    stpcpy(s, str);

    char *token = strtok(s, ":");
    while (token != NULL)
    {
        count++;
        token = strtok(NULL, ":");
    }
    if (count == 7)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
// Defect Line Format
// Defect No:Description:Module name:Functional area:Filed-on Date:Status:Type
void validDefect(defect *defectptr, char *str)
{
    char *newstr = (char *)calloc(strlen(str), sizeof(char));
    strcpy(newstr, str);
    char *token = strtok(newstr, ":");
    defectptr->defectID = (char *)calloc(strlen(token), sizeof(char));
    defectptr->defectID = token;
    token = strtok(NULL, ":");
    defectptr->description = (char *)calloc(strlen(token), sizeof(char));
    defectptr->description = token;
    token = strtok(NULL, ":");
    defectptr->moduleName = (char *)calloc(strlen(token), sizeof(char));
    defectptr->moduleName = token;
    token = strtok(NULL, ":");
    defectptr->functionalArea = (char *)calloc(strlen(token), sizeof(char));
    defectptr->functionalArea = token;
    token = strtok(NULL, ":");
    defectptr->date = (char *)calloc(strlen(token), sizeof(char));
    defectptr->date = token;
    token = strtok(NULL, ":");
    defectptr->status = (char *)calloc(strlen(token), sizeof(char));
    defectptr->status = token;
    token = strtok(NULL, ":");
    defectptr->type = (char *)calloc(strlen(token), sizeof(char));
    defectptr->type = token;
}
void displayvalidDefects(defect *arr[], int vdc)
{
    for (int i = 0; i < vdc; i++)
    {
        printf("\nID: %s Status: %s", arr[i]->defectID, arr[i]->status);
    }
}
void invalidDefect(char *str)
{
    char *newstr = (char *)calloc(strlen(str), sizeof(char));
    strcpy(newstr, str);
    char *token = strtok(newstr, ":");
    printf("\nInvalid Defect ID: %s", token);
    char *filename = "../data/invalidDefectList.txt";
    FILE *fp;
    fp = fopen(filename, "a");
    if (fp == NULL)
    {
        printf("\n--- Unable to write into output file ---\n");
        pthread_exit(NULL);
    }
    fprintf(fp, "%s", str);
    fclose(fp);
}
void *getDefect(void *file)
{
    pthread_mutex_lock(&lock);
    defect *defect_arr[MAXDEFECT];
    char *file_loc = (char *)file;

    FILE *fpr = fopen(file_loc, "r");
    if (fpr == NULL) // File Validation
    {
        printf("\n--- Cannot open file: %s\n", file_loc);
        pthread_exit(NULL);
    }

    // Reading from defect file
    char str[MAXSTRLEN + 1];
    int vdc = 0;
    while (1)
    {
        if (fgets(str, MAXSTRLEN, fpr) == NULL)
        {
            break;
        }
        if (checkValidity(str))
        {
            defect_arr[vdc] = (defect *)calloc(1, sizeof(defect));
            validDefect(defect_arr[vdc], str);
            vdc++;
        }
        else
        {
            invalidDefect(str);
        }
    }
    printf("\n\n--- Total Valid Defects: %d ---\n\n", vdc);
    displayvalidDefects(defect_arr, vdc);
    assignEmployee(defect_arr,vdc);

    for (int i = 0; i < vdc; i++)
    {
        free(defect_arr[i]);
    }

    fclose(fpr);
    pthread_mutex_unlock(&lock);
}