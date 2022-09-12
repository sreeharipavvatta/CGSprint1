/*
FILE NAME: main.c

DESCRIPTION: This file contains main() function which acts as a starting point of any program.
*/
#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <stdlib.h>
#include "../Header/fun_head.h"
#define SUCCESS 1
#define ERROR 0
#define MAXFILES 5 // Maximum Input Defect files is set to 5
pthread_t threadIDarr[MAXFILES]; // Array to store threadID of all child threads.
pthread_mutex_t lock; // lock is mutex variable used for synchronization.

/*
FUNCTION NAME: main()

DESCRIPTION: Input Defect files are taken as command line arguments.
Separate threads are created for each input file passed, an array is given to store all thread IDs.
Passes file location with the thread to getdefect function Wait for all child threads to join.

RETURNS: SUCCESS on Successfull execution of program
         ERROR on failure at any point.   
*/
int main(int argc, char *argv[])
{
    int n_files = argc - 1; // Total Defect Files to be checked
    printf("--- Total files in queue: %d ---", n_files);
    if (argc < 2)
    {
        printf("--- Insufficient argument passed. ---");
        printf("--- Usage: <executable> <defectfile1> <defectfile2> ... ---");
        exit(1);
    }
    // Initialising Mutex Lock
    // if (pthread_mutex_init(&lock, NULL) != 0)
    // {
    //     printf("\n--- Mutex initialisation failed ---\n");
    //     exit(1);
    // }

    // Creating Threads for each defect file
    int err; // err: captures error
    for (int i = 1; i < argc; i++)
    {
        printf("\n--- Creating Thread for file %d: %s ---\n", i, argv[i]);
        err = pthread_create(&threadIDarr[i - 1], NULL, (void *)getDefect, (void *)argv[i]);
        if (err)
        {
            printf("\n--- ERROR: %d while creating thread for file %d: %s ---\n", err, i, argv[i]);
            exit(1);
        }
    }

    // Waiting for child threads to join
    for (int i = 0; i < argc - 1; i++)
    {
        pthread_join(threadIDarr[i], NULL);
    }

    // pthread_mutex_destroy(&lock);
    pthread_exit(NULL);
    return SUCCESS;
}