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
struct employee{
    char *Id;
    char *Name;
    char *BUnit;
    char *Expertise;
    char *Designation;
    int n_defect;
    defect *assigned_arr[MAXDEFECT];
};
typedef struct employee Emp;

void *getDefect(void *str);
void assignEmployee(defect *arr[], int vdc);
void displayvalidDefects(defect *arr[], int vdc);


#endif //End of header file