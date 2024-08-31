/*
======================================================================================== 
Name: 17.c
Author: Gitika Pinjani
Description: Write a program to simulate online ticket reservation. Implement write lock
Write a program to open a file, store a ticket number and exit. Write a separate program, to
open the file, implement write lock, read the ticket number, increment the number and print
the new ticket number then close the file.
Date: 29th Aug, 2024
=========================================================================================
*/
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<stdio.h>

int main(){
	struct{
	int ticketNo;
	}db;
	struct flock lock;
	int fd;
	fd = open("db",O_RDWR);
	read(fd,&db,sizeof(db));
	lock.l_type=F_WRLCK;
	lock.l_whence=SEEK_SET;
	lock.l_start=0;
	lock.l_len=0;
	lock.l_pid=getpid();

fcntl(fd,F_SETLKW,&lock);
printf("Current ticket number before entering Critical section is %d.\n",db.ticketNo);
db.ticketNo++;
lseek(fd,0L,SEEK_SET);
printf("Inside the critical section.\n");
write(fd,&db,sizeof(db));
printf("your ticket no is %d ,\n",db.ticketNo);
printf("enter to leave critical section");
getchar();
lock.l_type=F_UNLCK;
printf("unlocked and out of the critical section.\n");
fcntl(fd,F_SETLK,&lock);
}

/*
output:

gitikapinjani@gitikapinjani-Victus-by-HP-Gaming-Laptop-15-fa0xxx:~/HandsOnList1-SS$ ./a.out
Current ticket number before entering Critical section is 5.
Inside the critical section.
your ticket no is 6 ,
enter to leave critical section
unlocked and out of the critical section.
gitikapinjani@gitikapinjani-Victus-by-HP-Gaming-Laptop-15-fa0xxx:~/HandsOnList1-SS$ 
*/
