/*
======================================================================================== 
Name: 1c.c
Author: Gitika Pinjani
Description: Create the following types of a files using (i) shell command (ii) system call
c. FIFO (mkfifo Library Function or mknod system call)
Date: 25th Aug, 2024
=========================================================================================
*/

#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>

int main()
{
char arr[80];
mkfifo("myfifo", 0666);
int fd = open("myfifo", O_WRONLY);
printf("%d\n", fd);
fgets(arr, 80,stdin);
printf("%s\n",arr); 
write(fd,arr,80);
close(fd);
return 0;
}
