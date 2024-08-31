/*
======================================================================================== 
Name: 10.c
Author: Gitika Pinjani
Description: Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10
bytes (use lseek) and write again 10 bytes.
a. check the return value of lseek
b. open the file with od and check the empty spaces in between the data.
Date: 27th Aug, 2024
=========================================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd;
    char buffer1[] = "Hello, world!";
    char buffer2[] = "Goodbye, world!";

    fd = open("fd.txt", O_RDWR | O_CREAT, 0666);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    if (write(fd, buffer1, 10) != 10) {
        perror("Error writing to file");
        return 1;
    }

    off_t offset = lseek(fd, 10, SEEK_CUR);
    if (offset == -1) {
        perror("Error seeking in file");
        return 1;
    }
	
    if (write(fd, buffer2, 10) != 10) {
        perror("Error writing to file");
        return 1;
    }

    close(fd);

    return 0;
}

/*
output:

gitikapinjani@gitikapinjani-Victus-by-HP-Gaming-Laptop-15-fa0xxx:~/HandsOnList1-SS$ cc 10.c
gitikapinjani@gitikapinjani-Victus-by-HP-Gaming-Laptop-15-fa0xxx:~/HandsOnList1-SS$ ./a.out
gitikapinjani@gitikapinjani-Victus-by-HP-Gaming-Laptop-15-fa0xxx:~/HandsOnList1-SS$ cat fd.txt
gitikapinjani@gitikapinjani-Victus-by-HP-Gaming-Laptop-15-fa0xxx:~/HandsOnList1-SS$ od -c fd.txt
0000000   H   e   l   l   o   ,       w   o   r  \0  \0  \0  \0  \0  \0
0000020  \0  \0  \0  \0   G   o   o   d   b   y   e   ,       w
0000036
gitikapinjani@gitikapinjani-Victus-by-HP-Gaming-Laptop-15-fa0xxx:~/HandsOnList1-SS$
*/
