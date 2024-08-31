/*
======================================================================================== 
Name: 16b.c
Author: Gitika Pinjani
Description: Write a program to perform mandatory locking.
b. Implement read lock
Date: 29th Aug, 2024
=========================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

void lock_file(int fd) {
    struct flock lock;
    lock.l_type = F_RDLCK; 
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;
    if (fcntl(fd, F_SETLKW, &lock) == -1) {
        perror("cannot get read lock");
        return ;
    } else {
        printf("Read lock acquired by PID %d.\n", getpid());
    }
}

void unlock_file(int fd) {
    struct flock lock;
    lock.l_type = F_UNLCK; 
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;
   fcntl(fd, F_SETLK, &lock);
        printf("Lock released by PID %d.\n", getpid());
}

int main() {
    const char *fp = "readlock.txt";
    int fd = open(fp, O_RDONLY| O_CREAT);
    lock_file(fd);
    printf("Reading file by PID %d...\n", getpid());
    sleep(20);
    unlock_file(fd);   
    close(fd);
    return 0;
}

/*
output:

gitikapinjani@gitikapinjani-Victus-by-HP-Gaming-Laptop-15-fa0xxx:~/HandsOnList1-SS$ ./a.out
Read lock acquired by PID 4215.
Reading file by PID 4215...
Lock released by PID 4215.
gitikapinjani@gitikapinjani-Victus-by-HP-Gaming-Laptop-15-fa0xxx:~/HandsOnList1-SS$ 


*/
