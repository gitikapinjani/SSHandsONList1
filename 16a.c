/*
======================================================================================== 
Name: 16a.c
Author: Gitika Pinjani
Description:Write a program to perform mandatory locking.
a. Implement write lock
Date: 29th Aug, 2024
=========================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

void lock_file(int fd,int type) {
    struct flock lock;

    lock.l_type = type;
    lock.l_start = 0;
    lock.l_whence = SEEK_SET;
    lock.l_len = 0;

    if (fcntl(fd, F_SETLKW, &lock) == -1) {
        perror("Failed to lock file. ");
        exit(EXIT_FAILURE);
    }else {
        if (type == F_WRLCK) {
            printf("File locked by process %d. \n", getpid());
        } else if (type == F_UNLCK) {
            printf("File unlocked by process %d. \n", getpid());
        }
    }
}

    int main() {
    char *file_path = "writelock.txt";
    int fd = open(file_path, O_RDWR | O_CREAT, 0644);
    if (fd == -1) {
        perror("Failed to open file.");
        exit(EXIT_FAILURE);
    }

    lock_file(fd,F_WRLCK);

    printf("Process %d  in critical section .\n", getpid());
    char *data = "testing.\n";
    if (write(fd, data, strlen(data)) == -1) {
        perror("Failed to write to the file.");
        exit(EXIT_FAILURE);
    }
    sleep(10);

    printf("Process %d is leaving critical section.\n", getpid());

    lock_file(fd, F_UNLCK);
    close(fd);

    return 0;
}

/*
output:

gitikapinjani@gitikapinjani-Victus-by-HP-Gaming-Laptop-15-fa0xxx:~/HandsOnList1-SS$ ./a.out
File locked by process 7614.
Process 7614  in critical section .
Process 7614 is leaving critical section.
File unlocked by process 7614.

*/
