/*
======================================================================================== 
Name: 14.c
Author: Gitika Pinjani
Description: Write a program to find the type of a file.
a. Input should be taken from command line.
b. program should be able to identify any type of a file.
Date: 28th Aug, 2024
=========================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <libgen.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf( "You have given wrong command line argument\n");
        return 1;
    }

    char *file_name = argv[1];
    struct stat sb;

    if (stat(file_name, &sb) == -1) {
        perror("stat");
        return 1;
    }

    if (S_ISREG(sb.st_mode)) {
        printf("Regular file\n");
    } else if (S_ISDIR(sb.st_mode)) {
        printf("Directory\n");
    } else if (S_ISCHR(sb.st_mode)) {
        printf("Character special file\n");
    } else if (S_ISBLK(sb.st_mode)) {
        printf("Block special file\n");
    } else if (S_ISFIFO(sb.st_mode)) {
        printf("FIFO (named pipe)\n");
    } else if (S_ISLNK(sb.st_mode)) {
        printf("Symbolic link\n");
    } else if (S_ISSOCK(sb.st_mode)) {
        printf("Socket\n");
    } else {
        printf("Unknown file type\n");
    }

    return 0;
}

/*
gitikapinjani@gitikapinjani-Victus-by-HP-Gaming-Laptop-15-fa0xxx:~/HandsOnList1-SS$ cc 14.c
gitikapinjani@gitikapinjani-Victus-by-HP-Gaming-Laptop-15-fa0xxx:~/HandsOnList1-SS$ ./a.out 2.c
Regular file
gitikapinjani@gitikapinjani-Victus-by-HP-Gaming-Laptop-15-fa0xxx:~/HandsOnList1-SS$ 
*/
