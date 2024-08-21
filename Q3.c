#include<stdlib.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>
int main(){
char *fileName = "fd.txt";
int fd= open(fileName, O_RDONLY | O_CREAT);
if(fd == -1)
{
printf("error");
return 1;
}

printf("file descriptor value: %d\n", fd);
close(fd);
} 

