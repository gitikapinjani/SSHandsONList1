/*
========================================================================================
Name: 30.c
Author: Gitika Pinjani
Description: Write a program to run a script at a specific time using a Daemon process.
Date: 31th Aug, 2024
=========================================================================================
*/


#include<unistd.h>
#include<sys/stat.h>
#include<stdio.h>
#include<stdlib.h>

int main(){
if(!fork()){
	setsid();
	chdir("/");
	umask(0);
	while(1){
		sleep(4);
		printf("child PID :: %d\n", getpid());
		printf("Daemon process is running in background .....\n");
}
}
else
	exit(0);
}

/*
output:

gitikapinjani@gitikapinjani-Victus-by-HP-Gaming-Laptop-15-fa0xxx:~/HandsOnList1-SS$ cc 30.c
gitikapinjani@gitikapinjani-Victus-by-HP-Gaming-Laptop-15-fa0xxx:~/HandsOnList1-SS$ ./a.out
gitikapinjani@gitikapinjani-Victus-by-HP-Gaming-Laptop-15-fa0xxx:~/HandsOnList1-SS$ child pid: 4066
Daemon process is running in background ....
child pid: 4066
Daemon process is running in background ....
child pid: 4066
Daemon process is running in background ....

*/
