/*
Filename: main.c
Description: This is our main file program starts from here.
*/
#include <stdio.h>
#include <pthread.h>
#include "../Header/fun_head.h"
#define SUCCESS 1
#define ERROR 0
int main(int argc, char *argv){

    getDefect("../data/defect.txt");



    return SUCCESS;
}