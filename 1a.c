/*
======================================================================================== 
Name: 1a.c
Author: Gitika Pinjnai
Description: Create the following types of a files using (i) shell command (ii) system call
a. soft link (symlink system call)
Date: 25th Aug, 2024
=========================================================================================
*/
#include<stdio.h>
#include<unistd.h>
int main(){
symlink("filenew","sftln");

perror("error");

}
/*
gitikapinjani@gitikapinjani-Victus-by-HP-Gaming-Laptop-15-fa0xxx:~/HandsOnList1-SS$ cc 1a.c
gitikapinjani@gitikapinjani-Victus-by-HP-Gaming-Laptop-15-fa0xxx:~/HandsOnList1-SS$ ./a.out
error: Success
gitikapinjani@gitikapinjani-Victus-by-HP-Gaming-Laptop-15-fa0xxx:~/HandsOnList1-SS$ 
*/
