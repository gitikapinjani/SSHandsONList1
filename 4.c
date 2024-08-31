/*
======================================================================================== 
Name: 4.c
Author: Gitika Pinjani
Description: Write a program to open an existing file with read write mode. Try O_EXCL flag also.
Date: 26th Aug, 2024
=========================================================================================
*/
#include<stdio.h>
#include<fcntl.h>
int main (void)
{
int fd;
fd = open("cars", O_RDWR| O_EXCL| O_CREAT, 0744);
printf("fd=%d\n",fd);
}

/*
output:

gitikapinjani@gitikapinjani-Victus-by-HP-Gaming-Laptop-15-fa0xxx:~/HandsOnList1-SS$ cc 4.c
gitikapinjani@gitikapinjani-Victus-by-HP-Gaming-Laptop-15-fa0xxx:~/HandsOnList1-SS$ ./a.out
fd=-1
*/
