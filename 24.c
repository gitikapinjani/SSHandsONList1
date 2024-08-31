/*
========================================================================================
Name: 24.c
Author: Gitika Pinjani
Description: Write a program to create an orphan process.
Date: 30th Aug, 2024
=========================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        return 1;
    }

    if (pid == 0) {
	sleep(5);
        printf("Child process:: PID = %d, PPID = %d\n", getpid(), getppid());
        printf("Child process:: exiting...\n");
        exit(0);
    } else {
        printf("Parent process:: PID = %d, PPID = %d\n", getpid(), getppid());
        printf("Parent process:: exiting...\n");
        exit(0);
    }
    return 0;
}

/*
gitikapinjani@gitikapinjani-Victus-by-HP-Gaming-Laptop-15-fa0xxx:~/HandsOnList1-SS$ cc 24.c
gitikapinjani@gitikapinjani-Victus-by-HP-Gaming-Laptop-15-fa0xxx:~/HandsOnList1-SS$ ./a.out
Parent process: pid = 5045, ppid = 2914
Parent process: exiting...
Child process: pid = 5046, ppid = 5045
gitikapinjani@gitikapinjani-Victus-by-HP-Gaming-Laptop-15-fa0xxx:~/HandsOnList1-SS$ Child process: exiting...
*/
