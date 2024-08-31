/*
======================================================================================== 
Name: 1b.c
Author: Gitika Pinjnai
Description: Create the following types of a files using (i) shell command (ii) system call
b. hard link (link system call)
Date: 25th Aug, 2024
=========================================================================================
*/
#include<stdio.h>
#include<unistd.h>
int main(){
link("filenew","hrdlnk");

perror("error");
}

/*
output:

gitikapinjani@gitikapinjani-Victus-by-HP-Gaming-Laptop-15-fa0xxx:~/HandsOnList1-SS$ cc 1b.c 
gitikapinjani@gitikapinjani-Victus-by-HP-Gaming-Laptop-15-fa0xxx:~/HandsOnList1-SS$ ./a.out
error: Success
gitikapinjani@gitikapinjani-Victus-by-HP-Gaming-Laptop-15-fa0xxx:~/HandsOnList1-SS$ 
*/
