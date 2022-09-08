/*
Filename: getdefect.c
Description: Read all defects from input file.
*/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define SUCCESS 1
#define ERROR 0
#define MAXDEFECT 10
#define MAXSTRLEN 200
struct defect
{
    char *defectID;
    char *description;
    char *moduleName;
    char *functionalArea;
    char *date;
    char *status;
    char *type;
};
typedef struct defect defect;
void checkValidity(char *str)
{
    printf("\n--- Got this: %s ---\n", str);
}
void validDefect(defect *defect_arr, char *str)
{
    
}
void invalidDefect(char *defectID, char *str)
{
    printf("Invalid Defect ID : %s\n",defectID);
	char *filename = "../data/invalidDefectList.txt";
	FILE *fp;
	fp = fopen(filename, "a");
	 if (fp == NULL)
    {
       printf("Issue in opening the input file");
	   return EXIT_FAILURE;
    }
	fprintf(fp, "%s\n", str);
	fclose(fp);

}
void *getDefect(void *file)
{
    defect *defect_arr[MAXDEFECT];
    char *file_loc = (char *)file;

    FILE *fpr = fopen(file_loc, "r");
    if (fpr == NULL) //File Validation
    {
        printf("cannot open file - %s\n", file_loc);
        exit(1);
    }

    //Reading from defect file
    char str[MAXSTRLEN + 1];
    while (1)
    {
        if (fgets(str, MAXSTRLEN, fpr) == NULL)
        {
            break;
        }
        checkValidity(str);
    }
    
    fclose(fpr);
    
}