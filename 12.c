/*
========================================================================================
Name: 12.c
Author: Gitika Pinjani
Description: Write a program to find out the opening mode of a file. Use fcntl.
Date: 28th Aug, 2024
=========================================================================================
*/


#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main(){
char filepath[]="cars";

int fd;
fd = open(filepath, O_RDWR,0644);

int flag = fcntl(fd,F_GETFL);

if(flag == 32768)
	printf("file is opened in read only mode\n");
else if(flag ==32769)
	printf("file is opened in write only mode\n");
else if(flag ==32770)
	printf("file is opened in read write mode\n");
}


/*
Output:
file is opened in read write mode
*/
