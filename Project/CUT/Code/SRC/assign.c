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
    char *f_loc="../data/employee.txt"; //Location of Employee Database
    int count=0;
    /*
    arr[] is array of Employee Structure
    Create File Pointer to open employee.txt
    Display proper error if file cannot be opened anyhow.

    Tokenise each line of file and store information inside arr[]
    
    While storing insitialise Employee->n_defect =0;
    */



    return count;

}
void displayEmployees(Emp *arr[], int n_emp)
{
    for (int i = 0; i < n_emp; i++)
    {
        printf("\nID: %s Name: %s", arr[i]->Id, arr[i]->Name);
    }
}
void unassignedDefect(defect *defectptr){
    /*
    defectptr contains structure of defect
    Append whole information into a file "unassignedDefect.txt"
    Create file if not present inside Project/CUT/Code/data/

    Also display proper message on the terminal

    */
}
void searchProgrammer(defect *defectptr, Emp *arr[]){
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

}
void createEmployeeFile(Emp *arr[]){
    /*
    arr[] is array of Employee Structure
    Loop on arr, if at some index arr[index]->n_defect >0
    Which means there is some defect assigned to the employee

    Create a file with name <arr[index]->Id>_assignments.txt

    Put following information inside the file in one line for each assignment.
    defects ID, defect description, module name, functional area,
    filed-on date type, Emp ID and EMP Name.


    */
}
void assignEmployee(defect *arr[], int vdc)
{
    Emp *emp_arr[MAXEMP]; //Array of Employee structure
    int n_emp=getEmployee(emp_arr); //n_emp: No of employees in database

    printf("\n\n--- Total Employee: %d ---\n\n", n_emp);
    displayEmployees(emp_arr, n_emp);

    /*
    Loop on defect arr
    If defect status = open
    send that defect to searchProgrammer fn


    */
    
    // displayvalidDefects(arr, vdc);
}