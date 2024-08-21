#include<stdio.h>
#include<fcntl.h>
int main (void)
{
int fd;
fd = open("cars", O_RDWR| O_EXCL| O_CREAT, 0744);
printf("fd=%d\n",fd);
}
