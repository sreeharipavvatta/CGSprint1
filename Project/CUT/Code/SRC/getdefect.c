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
int checkValidity(defect *defect_arr,char *str){
    int count=0;
    char *s = (char*)calloc(sizeof(str),sizeof(char));
    s = str;

           char* token = strtok(s,":");
        while(token != NULL){
             count++;
             switch (count)
             {
             case 1 : defect_arr->defectID=(char*)calloc(sizeof(token),sizeof(char));
                      defect_arr->defectID=token; break;
             case 2 : defect_arr->description=(char*)calloc(sizeof(token),sizeof(char));
                      defect_arr->description=token; break;
             case 3 : defect_arr->moduleName=(char*)calloc(sizeof(token),sizeof(char));
                      defect_arr->moduleName=token; break;
             case 4 : defect_arr->functionalArea=(char*)calloc(sizeof(token),sizeof(char));
                      defect_arr->functionalArea=token; break;
             case 5 : defect_arr->date=(char*)calloc(sizeof(token),sizeof(char));
                      defect_arr->date=token; break;
             case 6 : defect_arr->status=(char*)calloc(sizeof(token),sizeof(char));
                      defect_arr->status=token; break;
             case 7 : defect_arr->type=(char*)calloc(sizeof(token),sizeof(char));
                      defect_arr->type=token; break;
             default:break;
             }
             token = strtok(NULL,":");
        }

        if(count!=7||defect_arr->status!="open"){
           if(count!=7){
              invalidDefect(defect_arr->defectID,str);
           }
           free(defect_arr->defectID);
           free(defect_arr->description);
           free(defect_arr->moduleName);
           free(defect_arr->functionalArea);
           free(defect_arr->date);
           free(defect_arr->status);
           free(defect_arr->type);

           return 0;
        }
        else{
            defect_arr->status ="close";
        }
        return 1;
    }
      

void invalidDefect(char* defectID,char *str){

}

void getDefect(char *file_loc){
    defect * defect_arr[MAXDEFECT];

  char str[MAXSTRLEN + 1];
  int i=0;
    while (1)
    {
        if (fgets(str, MAXSTRLEN, fpr) == NULL)
        {
            break;
        }
        i++;
        if(!checkValidity(str,defect_arr[i])){
        i--;
    }
    }
    
    
}