/*
Filename: getdefect.c
Description: Read all defects from input file.
*/
#include <stdio.h>
#include <pthread.h>
#include <string.h>
#define SUCCESS 1
#define ERROR 0
#define MAXDEFECT 10
struct defect{
    char *defectID;
    char *description;
    char *moduleName;
    char *functionalArea;
    char *date;
    char *status;
    char *type;

};
typedef struct defect defect;

//Defect No:Description:Module name:Functional area:Filed-on Date:Status:Type 
void checkValidity(char *str){
    int count=0;
    while(1){
        char *status;
        char* token = strtok(str,":");
        while(token != NULL){
            count++;
            if(count==6){
                status = token;
            }
        }
        if(count==7){
          if(status=="open")
           validDefect(defect_arr,str);
        }
        else{
            invalidDefect(str);
        }
    }
      
}
void validDefect(defect *defect_arr, char *str){
     

}
void invalidDefect(char *str){

}
void getDefect(char *file_loc){
    defect * defect_arr[MAXDEFECT];

}