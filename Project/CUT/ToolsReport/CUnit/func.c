#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "header.h"
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