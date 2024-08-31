/*
======================================================================================== 
Name: 9.c
Author: Gitika Pinjani
Description: Write a program to print the following information about a given file.
a. inode
b. number of hard links
c. uid
d. gid
e. size
f. block size
g. number of blocks
h. time of last access
i. time of last modification
j. time of last change
Date: 27th Aug, 2024
=========================================================================================
*/
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>

int main(int argv, char* argc[]) {
    struct stat sb;
    if (stat(argc[1], &sb) == -1) {
        perror("Error getting file stats");
        return 1;
    }

    printf("File informations: \n");
    printf("a. inode: %lu.\n", sb.st_ino);
    printf("b. number of hard links: %lu. \n", sb.st_nlink);
    printf("c. uid: %u. \n", sb.st_uid);
    printf("d. gid: %u. \n", sb.st_gid);
    printf("e. size: %lu bytes. \n", sb.st_size);
    printf("f. block size: %lu bytes. \n", sb.st_blksize);
    printf("g. number of blocks: %lu. \n", sb.st_blocks);
    printf("h. time of last access: %s .", ctime(&sb.st_atime));
    printf("i. time of last modification: %s. ", ctime(&sb.st_mtime));
    printf("j. time of last change: %s. ", ctime(&sb.st_ctime));

    return 0;
}

/*
gitikapinjani@gitikapinjani-Victus-by-HP-Gaming-Laptop-15-fa0xxx:~/HandsOnList1-SS$ cc 9.c
gitikapinjani@gitikapinjani-Victus-by-HP-Gaming-Laptop-15-fa0xxx:~/HandsOnList1-SS$ ./a.out fd.txt
File information:
a. inode: 6162235
b. number of hard links: 1
c. uid: 1000
d. gid: 1000
e. size: 30 bytes
f. block size: 4096 bytes
g. number of blocks: 8
h. time of last access: Sat Aug 31 22:09:30 2024
i. time of last modification: Sat Aug 31 22:09:24 2024
j. time of last change: Sat Aug 31 22:09:24 2024
gitikapinjani@gitikapinjani-Victus-by-HP-Gaming-Laptop-15-fa0xxx:~/HandsOnList1-SS$ 
*/
