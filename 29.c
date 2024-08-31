/*
========================================================================================
Name: 29.c
Author: Gitika Pinjani
Description: Write a program to get scheduling policy and modify the scheduling policy (SCHED_FIFO,
SCHED_RR).
Date: 31th Aug, 2024
=========================================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sched.h>

int main(){

int schPolicy;
struct sched_param param;

schPolicy=sched_getscheduler(0);
if(schPolicy == -1)
{
perror("error in fetching the scheduling policy. ");
exit(EXIT_FAILURE);
}

if(schPolicy == SCHED_RR)
  printf("The current policy is SCHED_RR. \n");
else if(schPolicy == SCHED_FIFO)
  printf("The current policy is SCHED_FIFO. \n");
else if(schPolicy == SCHED_OTHER)
  printf("The current policy is SCHED_OTHER. \n");
else
  printf("The current policy is not known. \n");

param.sched_priority=1;
if(sched_setscheduler(0,SCHED_RR, &param)==-1)
{
perror("error in changing policy to SCHED_RR. \n");
exit(EXIT_FAILURE);
}
printf("Scheduling policy is now modified to SCHED_RR. \n");

param.sched_priority=1;
if(sched_setscheduler(0,SCHED_FIFO, &param)==-1)
{
perror("error in changing policy to SCHED_FIFO. \n");
exit(EXIT_FAILURE);
}
printf("Scheduling policy is now modified to SCHED_FIFO. \n");

exit(EXIT_SUCCESS);
}

/*
gitikapinjani@gitikapinjani-Victus-by-HP-Gaming-Laptop-15-fa0xxx:~/HandsOnList1-SS$ cc 29.c
gitikapinjani@gitikapinjani-Victus-by-HP-Gaming-Laptop-15-fa0xxx:~/HandsOnList1-SS$ sudo ./a.out
The current policy is SCHED_OTHER
Scheduling policy is now modified to SCHED_RR
Scheduling policy is now modified to SCHED_FIFO
gitikapinjani@gitikapinjani-Victus-by-HP-Gaming-Laptop-15-fa0xxx:~/HandsOnList1-SS$
*/
