/*
Filename: main.c
Description: This is our main file program starts from here.
*/
#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <stdlib.h>
#include "../Header/fun_head.h"
#define SUCCESS 1
#define ERROR 0
#define MAXFILES 5
pthread_t threadIDarr[MAXFILES];
pthread_mutex_t lock;
int main(int argc, char *argv[])
{
    int n_files=argc-1; //Total Defect Files to be checked
    printf("--- Total files in queue: %d ---", n_files);
    if (argc < 2)
    {
        printf("--- Insufficient argument passed. ---");
        printf("--- Usage: <executable> <defectfile1> <defectfile2> ... ---");
        exit(1);
    }
    //Initialising Mutex Lock
    if (pthread_mutex_init(&lock, NULL) != 0)
    {
        printf("\n--- Mutex init failed ---\n");
        exit(1);
    }

    //Creating Threads for each defect file
    int err; //err: captures error
    for (int i = 1; i < argc; i++)
    {
        printf("\n--- Creating Thread for file %d: %s ---\n", i, argv[i]);
        err = pthread_create(&threadIDarr[i - 1], NULL, (void *)getDefect, (void *)argv[i]);
        if (err)
        {
            printf("\n ERROR: %d while creating thread for file %d: %s\n", err, i, argv[i]);
            exit(1);
        }
    }
    

    //Waiting for child threads to join
    for (int i = 0; i < argc - 1; i++)
    {
        pthread_join(threadIDarr[i], NULL);
    }

    
    pthread_mutex_destroy(&lock);
    pthread_exit(NULL);
    return SUCCESS;
}