#include<stdio.h>
#include<stdlib.h>
#define SIZE 200
int getDefects(char *strin)
{
	if(strin[0]=='\0')//to verify whether the content is received
	{
		printf("string is invalid\n");
		return(EXIT_FAILURE);
	}
	FILE *fpr=fopen(strin,"r");
	if(fpr==NULL)
	{
		printf("cannot open file - %s\n",strin);
		return(EXIT_FAILURE);
	}
	char str[SIZE+1];
	while(1)
	{
		if(fgets(str,SIZE,fpr)==NULL)
		{
			break;
		}
	//	printf("%s\n",str);
		int i = checkValidity(str);
	}
	fclose(fpr);
	return(EXIT_SUCCESS);
}
/* to check the function alone
 * comment line number 31 and use the main function and giving proper file name 
int main()
{
	char str[]="student.dat";
	int i=getDefects(str);
	return EXIT_SUCCESS;
}
