/*
========================================================================================
Name: 11c.c
Author: Gitika Pinjani
Description: Write a program to open a file, duplicate the file descriptor and append the file with both the
descriptors and check whether the file is updated properly or not.
c. use fcntl
Date: 28th Aug, 2024
=========================================================================================
*/


#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
int fd1,fd2;
char buffer1[] = "dup3 hello";
char buffer2[] = "bye";
fd1 = open("cars", O_RDWR| O_APPEND);
fd2=fcntl(fd1,F_DUPFD);
write(fd1, buffer1, sizeof(buffer1));
write(fd2, buffer2, sizeof(buffer2));
close(fd1);
close(fd2);

}

/*
gitikapinjani@gitikapinjani-Victus-by-HP-Gaming-Laptop-15-fa0xxx:~/HandsOnList1-SS$ cc 11c.c
gitikapinjani@gitikapinjani-Victus-by-HP-Gaming-Laptop-15-fa0xxx:~/HandsOnList1-SS$ ./a.out
gitikapinjani@gitikapinjani-Victus-by-HP-Gaming-Laptop-15-fa0xxx:~/HandsOnList1-SS$ cat cars

hellobyedup2 hellobyedup3 hellobye gitikapinjani@gitikapinjani-Victus-by-HP-Gaming-Laptop-15-fa0xxx:~/HandsOnList1-SS$ 



*/
