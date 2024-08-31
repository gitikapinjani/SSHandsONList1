/*
======================================================================================== 
Name: 20.c
Author: Gitika Pinjani
Description: Find out the priority of your running program. Modify the priority with nice command.
Date: 29th Aug, 2024
=========================================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>

int main()
{
pid_t pid = getpid();

int priority =  getpriority(PRIO_PROCESS , pid);
printf("Current Priority of the process is : %d.\n" , priority);

int new_priority = nice(10);

if(new_priority == -1)
perror("error.");
else
printf("New priority after nice(10): %d.\n",getpriority(PRIO_PROCESS,pid));
}

/*
output:

gitikapinjani@gitikapinjani-Victus-by-HP-Gaming-Laptop-15-fa0xxx:~/HandsOnList1-SS$ cc 20.c
gitikapinjani@gitikapinjani-Victus-by-HP-Gaming-Laptop-15-fa0xxx:~/HandsOnList1-SS$ ./a.out
Current Priority of the process is : 0.
New priority after nice(10): 10.
gitikapinjani@gitikapinjani-Victus-by-HP-Gaming-Laptop-15-fa0xxx:~/HandsOnList1-SS$ 

*/
