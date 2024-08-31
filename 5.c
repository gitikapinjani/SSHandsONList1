/*
======================================================================================== 
Name: 5.c
Author: Gitika Pinjani
Description: Write a program to create five new files with infinite loop. Execute the program in the background
and check the file descriptor table at /proc/pid/fd.
Date: 26th Aug, 2024
=========================================================================================
*/
#include<stdio.h>
#include<fcntl.h>
int main(){
int f1,f2,f3,f4,f5;

f1 = open("file1", O_RDWR|O_CREAT, 0744);
f2 = open("file2", O_RDWR|O_CREAT, 0744);
f3 = open("file3", O_RDWR|O_CREAT, 0744);
f4 = open("file4", O_RDWR|O_CREAT, 0744);
f5 = open("file5", O_RDWR|O_CREAT, 0744);

while(1);

}

/*
output:

gitikapinjani@gitikapinjani-Victus-by-HP-Gaming-Laptop-15-fa0xxx:/home$ ls -l /proc/4882/fd
total 0
lrwx------ 1 gitikapinjani gitikapinjani 64 Aug 31 22:27 0 -> /dev/pts/0
lrwx------ 1 gitikapinjani gitikapinjani 64 Aug 31 22:27 1 -> /dev/pts/0
lrwx------ 1 gitikapinjani gitikapinjani 64 Aug 31 22:27 2 -> /dev/pts/0
lrwx------ 1 gitikapinjani gitikapinjani 64 Aug 31 22:27 3 -> /home/gitikapinjani/HandsOnList1-SS/file1
lrwx------ 1 gitikapinjani gitikapinjani 64 Aug 31 22:27 4 -> /home/gitikapinjani/HandsOnList1-SS/file2
lrwx------ 1 gitikapinjani gitikapinjani 64 Aug 31 22:27 5 -> /home/gitikapinjani/HandsOnList1-SS/file3
lrwx------ 1 gitikapinjani gitikapinjani 64 Aug 31 22:27 6 -> /home/gitikapinjani/HandsOnList1-SS/file4
lrwx------ 1 gitikapinjani gitikapinjani 64 Aug 31 22:27 7 -> /home/gitikapinjani/HandsOnList1-SS/file5
gitikapinjani@gitikapinjani-Victus-by-HP-Gaming-Laptop-15-fa0xxx:/home$ 

*/
