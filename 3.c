/*
======================================================================================== 
Name: 3.c
Author: Gitika Pinjani
Description: Write a program to create a file and print the file descriptor value. Use creat ( ) system call
Date: 25th Aug, 2024
=========================================================================================
*/
#include<stdlib.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>
int main(){
char *fileName = "fd.txt";
int fd= open(fileName, O_RDONLY | O_CREAT);
if(fd == -1)
{
printf("error");
return 1;
}

printf("file descriptor value: %d\n", fd);
close(fd);
} 

/*
output:

gitikapinjani@gitikapinjani-Victus-by-HP-Gaming-Laptop-15-fa0xxx:~/HandsOnList1-SS$ cc 3.c
gitikapinjani@gitikapinjani-Victus-by-HP-Gaming-Laptop-15-fa0xxx:~/HandsOnList1-SS$ ./a.out
file descriptor value: 3

*/

