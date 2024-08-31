/*
======================================================================================== 
Name: 19.c
Author: Gitika Pinjani
Description: Write a program to find out time taken to execute getpid system call. Use time stamp counter.
Date: 29th Aug, 2024
=========================================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<sys/time.h>
unsigned long long rdtsc(){
	unsigned long long dst;
	__asm__ __volatile__("rdtsc":"=A" (dst));
}

int main(){
	int i, nano;
	unsigned long long int start, end;
	start = rdtsc();
	for(i=0;i<=10000;i++)
		getpid();
	end = rdtsc();
	nano = (end - start)/2.4;
	printf("Time taken by getpid() = %d nano sec. \n",nano);
}
/*
gitikapinjani@gitikapinjani-Victus-by-HP-Gaming-Laptop-15-fa0xxx:~/HandsOnList1-SS$ cc 19.c
gitikapinjani@gitikapinjani-Victus-by-HP-Gaming-Laptop-15-fa0xxx:~/HandsOnList1-SS$ ./a.out
Time taken by getpid() = 1700609 nano sec. 
gitikapinjani@gitikapinjani-Victus-by-HP-Gaming-Laptop-15-fa0xxx:~/HandsOnList1-SS$ 
*/
