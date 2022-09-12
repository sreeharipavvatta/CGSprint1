#include<stdio.h>
#include<string.h>
#include<stdlib.h>
/*
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
typedef struct employee Emp;*/
void searchProgrammer(defect *defectptr, Emp *arr[])
{
	int i=0,foundflag=0;
	printf("defect %s\n",defectptr->status);
	printf("employee %s\n",arr[0]->Name);
	if(strcmp(defectptr->status,"assigned")==0)
	{
		printf("defect already assigned\n");
		return;
	}
	for(i=0;arr[i]!=NULL/* need to give proper limit*/;i++)
	{
		if(strcmp(defectptr->functionalArea,arr[i]->Expertise)==0)
		{
			foundflag=1;
			defectptr->status="assigned";
			arr[i]->n_defect++;
			arr[i]->assigned_arr[(arr[i]->n_defect)-1]=defectptr;
			break;
		}
	}
	if(foundflag==0)
	{
		printf("programmer not found\n");
		unassignedDefect(defectptr);
		return;
	}
	else
	{
		printf("ID %s Status: %s\n",defectptr->defectID,defectptr->status);
		printf("ModuleName = %s\nfunctional area = %s\ndescription=%s\nEmployee Id = %s\nEmployee Name %s\n",defectptr->moduleName, defectptr->functionalArea,defectptr->description,arr[i]->Id,arr[i]->Name);
	}



}
/*
void main()
{
	defect d;
	d.defectID="DID1";
	d.description="SampleError";
	d.moduleName="sampleModule";
	d.functionalArea="Softwar";
	d.date="abs";
	d.status="open";
	d.type="sampletype";
	Emp* arr[2];
	arr[0]=(Emp*)calloc(1,sizeof(Emp));
	arr[1]=(Emp*)calloc(1,sizeof(Emp));
	arr[0]->Id="123123";
	arr[0]->Name="Sample1";
	arr[0]->BUnit="SampleBunit";
	arr[0]->Expertise="Hardware";
	arr[0]->Designation="manager";
	arr[0]->n_defect=0;
	for(int i=0;i<5;i++)
	{
		arr[0]->assigned_arr[i]=(defect*)calloc(1,sizeof(defect));
	}

	arr[1]->Id="12453";
	arr[1]->Name="Sample2";
	arr[1]->BUnit="SampleBunit2";
	arr[1]->Expertise="Software";
	arr[1]->Designation="manager2";
	arr[1]->n_defect=0;
	for(int i=0;i<5;i++)
	{
		arr[1]->assigned_arr[i]=(defect*)calloc(1,sizeof(defect));
	}
	printf("did = %s && %d",d.status,sizeof(arr[1]->assigned_arr[1]));
	searchProgrammer(&d,arr);
}
*/

