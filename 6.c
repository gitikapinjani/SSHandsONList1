/*
======================================================================================== 
Name: 6.c
Author: Gitika Pinjani
Description: Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls
Date: 27th Aug, 2024
=========================================================================================
*/
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main(){
char b[10];
read(0, b, sizeof(b));
write(1,b, sizeof(b));
}

/*
output:

gitikapinjani@gitikapinjani-Victus-by-HP-Gaming-Laptop-15-fa0xxx:~/HandsOnList1-SS$ cc 6.c
gitikapinjani@gitikapinjani-Victus-by-HP-Gaming-Laptop-15-fa0xxx:~/HandsOnList1-SS$ ./a.out
hello!
hello!
gitikapinjani@gitikapinjani-Victus-by-HP-Gaming-Laptop-15-fa0xxx:~/HandsOnList1-SS$ 

*/
