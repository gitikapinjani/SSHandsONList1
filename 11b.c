/*
========================================================================================
Name: 11b.c
Author: Gitika Pinjani
Description: Write a program to open a file, duplicate the file descriptor and append the file with both the
descriptors and check whether the file is updated properly or not.
b. use dup2
Date: 28th Aug, 2024
=========================================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
int fd1,fd2;
char buffer1[] = "dup2 hello";
char buffer2[] = "bye";
fd1 = open("cars", O_RDWR| O_APPEND);
dup2(fd1, fd2);
write(fd1, buffer1, sizeof(buffer1));

write(fd2, buffer2, sizeof(buffer2));
close(fd1);
close(fd2);
}

/*
gitikapinjani@gitikapinjani-Victus-by-HP-Gaming-Laptop-15-fa0xxx:~/HandsOnList1-SS$ cc 11b.c
gitikapinjani@gitikapinjani-Victus-by-HP-Gaming-Laptop-15-fa0xxx:~/HandsOnList1-SS$ ./a.out
gitikapinjani@gitikapinjani-Victus-by-HP-Gaming-Laptop-15-fa0xxx:~/HandsOnList1-SS$ nano cars
gitikapinjani@gitikapinjani-Victus-by-HP-Gaming-Laptop-15-fa0xxx:~/HandsOnList1-SS$ cat cars

hellobyedup2 hellobye gitikapinjani@gitikapinjani-Victus-by-HP-Gaming-Laptop-15-fa0xxx:~/HandsOnList1-SS$ 
*/
