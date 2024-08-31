/*
======================================================================================== 
Name: 21.c
Author: Gitika Pinjani
Description: Write a program, call fork and print the parent and child process id.
Date: 30th Aug, 2024
=========================================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main(){

pid_t pid;
pid = fork();

if(pid ==0)
printf("child process PID:: %d.\n", getpid());
else
printf("parent process PID:: %d.\n", getpid());

return 0;

}

/*
output:

gitikapinjani@gitikapinjani-Victus-by-HP-Gaming-Laptop-15-fa0xxx:~/HandsOnList1-SS$ cc 21.c
gitikapinjani@gitikapinjani-Victus-by-HP-Gaming-Laptop-15-fa0xxx:~/HandsOnList1-SS$ ./a.out
parent process PID:: 3479.
child process PID:: 3480.
gitikapinjani@gitikapinjani-Victus-by-HP-Gaming-Laptop-15-fa0xxx:~/HandsOnList1-SS$ 

*/
