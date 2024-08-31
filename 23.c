/*
======================================================================================== 
Name: 23.c
Author: Gitika Pinjani
Description: Write a program to create a Zombie state of the running program.
Date: 30th Aug, 2024
=========================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        return 1;
    }

    if (pid == 0) { // child process
        printf("Child process: exiting without being waited...\n");
        exit(0);
    } else { // parent process
        printf("Parent process: not waiting for child...\n");
        sleep(10); // sleep for 10 seconds to allow child to exit
        printf("Parent process: exiting...\n");
        exit(0);
    }
    return 0;
}

/*
output: 

gitikapinjani@gitikapinjani-Victus-by-HP-Gaming-Laptop-15-fa0xxx:~/HandsOnList1-SS$ cc 23.c
gitikapinjani@gitikapinjani-Victus-by-HP-Gaming-Laptop-15-fa0xxx:~/HandsOnList1-SS$ ./a.out
Parent process: not waiting for child...
Child process: exiting without being waited...
Parent process: exiting...
gitikapinjani@gitikapinjani-Victus-by-HP-Gaming-Laptop-15-fa0xxx:~/HandsOnList1-SS$ 

*/
