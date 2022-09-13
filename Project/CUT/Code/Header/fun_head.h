/*
FILE NAME: fun_head.h

DESCRIPTION: It is our user-defined header file.
It contains function declarations and structure declarations that are used in this application.
*/
#ifndef FUN_HEAD
#define FUN_HEAD
#define MAXDEFECT 10
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
struct employee
{
    char *Id;
    char *Name;
    char *BUnit;
    char *Expertise;
    char *Designation;
    pthread_mutex_t emplock;
    int n_defect;
    defect *assigned_arr[MAXDEFECT];
};
typedef struct employee Emp;

void *getDefect(void *str);
void assignEmployee(defect *arr[], int vdc);
void displayvalidDefects(defect *arr[], int vdc);
int getEmployee(Emp *arr[]);
void displayEmployees(Emp *arr[], int n_emp);
void createEmployeeFile(Emp *emp_ptr, defect *defectptr);
int checkValidity(char *str);

#endif // End of header file