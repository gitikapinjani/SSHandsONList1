/*
======================================================================================== 
Name: 28.c
Author: Gitika Pinjani
Description: Write a program to get maximum and minimum real time priority.
Date: 31th Aug, 2024
=========================================================================================
*/


#include <stdio.h>
#include <sched.h>

int main() {
    int maxRR, minRR, maxOther, minOther, maxFifo, minFifo;

    maxRR = sched_get_priority_max(SCHED_RR);
    minRR = sched_get_priority_min(SCHED_RR);

    maxOther = sched_get_priority_max(SCHED_OTHER);
    minOther = sched_get_priority_min(SCHED_OTHER);

    maxFifo = sched_get_priority_max(SCHED_FIFO);
    minFifo = sched_get_priority_min(SCHED_FIFO);

    printf("Maximum real-time priority of RR:: %d.\n", maxRR);
    printf("Minimum real-time priority of RR:: %d.\n", minRR);
    printf("Maximum real-time priority of OTHER:: %d.\n", maxOther);
    printf("Minimum real-time priority of OTHER:: %d.\n", minOther);
    printf("Maximum real-time priority of FIFO:: %d.\n", maxFifo);
    printf("Minimum real-time priority of FIFO:: %d.\n", minFifo);
}

/*

Output:

gitikapinjani@gitikapinjani-Victus-by-HP-Gaming-Laptop-15-fa0xxx:~/HandsOnList1-SS$ nano 28.c
gitikapinjani@gitikapinjani-Victus-by-HP-Gaming-Laptop-15-fa0xxx:~/HandsOnList1-SS$ cc 28.c
gitikapinjani@gitikapinjani-Victus-by-HP-Gaming-Laptop-15-fa0xxx:~/HandsOnList1-SS$ ./a.out
Maximum real-time priority of RR: 99
Minimum real-time priority of RR: 1
Maximum real-time priority of OTHER: 0
Minimum real-time priority of OTHER: 0
Maximum real-time priority of FIFO: 99
Minimum real-time priority of FIFO: 1
gitikapinjani@gitikapinjani-Victus-by-HP-Gaming-Laptop-15-fa0xxx:~/HandsOnList1-SS$
*/
