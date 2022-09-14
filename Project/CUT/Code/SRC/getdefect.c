/*
FILE NAME: getdefect.c

DESCRIPTION: It reads all lines of defect information contained inside input files.
Tokenises each line and store valid defects into array of defect structure.
*/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include "../Header/fun_head.h"
#define SUCCESS 1
#define ERROR 0
#define MAXDEFECT 10  // Maximum Number of Defects in each input file is set to 10
#define MAXSTRLEN 200 // Maximum String length is set to 200
/*
FUNCTION NAME: checkValidity()

DESCRIPTION: It take the defect line as an argument, the line breaks into two different parts.
If required information is given consider as valid entry.
Else consider it as invalid entry and pass it to the invalidDefect() function.
For all valid entries, store values in a proper data structures.
All defects are stored inside an array of defect structure.
At last, passes this array with valid entries to assign Programmer Function


RETURNS: 1 in case of valid entry.
         0 in case of invalid entry.
*/
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
/*
FUNCTION NAME: validDefect()

DESCRIPTION: It takes valid Defect strucuture and Defect String/Line as Input.
Tokenises string and stores it in the defect structure.

RETURNS: void
*/
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
/*
FUNCTION NAME: displayValidDefects()

DESCRIPTION: It take array of defects as argument and displays all defect elements.

RETURNS: void
*/
void displayvalidDefects(defect *arr[], int vdc)
{
    for (int i = 0; i < vdc; i++)
    {
        printf("\nID: %s Status: %s", arr[i]->defectID, arr[i]->status);
    }
}
/*
FUNCTION NAME: invalidDefect()

DESCRIPTION: Displays proper error for invalid Defects and stores them inside a file
named as "invalidDefectList.txt"

RETURNS: void
*/
void invalidDefect(char *str)
{
    char *newstr = (char *)calloc(strlen(str), sizeof(char));
    strcpy(newstr, str);
    char *token = strtok(newstr, ":");
    printf("\nDefect ID: %s contains insufficient information.", token);
    char *filename = "../data/out/invalidDefect.txt";
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

/*
FUNCTION NAME: getDefect

DESCRIPTION: It takes the location of file as input.
Open the file with a file pointer, if the pointer is NULL print "cannot open file" and exit.
Reads each line of the file  if the line returns NULL break the loop as we have reached the end of file.
Else pass the content to check validity function.

RETRUNS: Void {Nothing}
*/
void *getDefect(void *file)
{
    // pthread_mutex_lock(&lock);
    defect *defect_arr[MAXDEFECT];
    char *file_loc = (char *)file;

    FILE *fpr = fopen(file_loc, "r");
    if (fpr == NULL) // File Validation
    {
        printf("\n--- Cannot open file: %s\n", file_loc);
        pthread_exit(NULL);
    }
    printf("\n--- Processing file: %s", file_loc);

    // Reading from defect file
    char str[MAXSTRLEN];
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
    fclose(fpr);
    
    assignEmployee(defect_arr, vdc);

    for (int i = 0; i < vdc; i++)
    {
        free(defect_arr[i]);
    }
    
}