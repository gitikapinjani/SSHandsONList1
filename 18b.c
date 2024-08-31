/*
======================================================================================== 
Name: 18b.c
Author: Gitika Pinjani
Description: Write a program to perform Record locking.
a. Implement write lock
b. Implement read lock
Create three records in a file. Whenever you access a particular record, first lock it then modify/access
to avoid race condition.
Date: 25th Aug, 2024
=========================================================================================
*/
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>

#define COURSE_RECORD_SIZE sizeof(int) * 2

struct {
    int courseNo;
    int rollNo;
} db2[3] = {
    {0, 1},
    {0, 2},
    {0, 3}  
};

int lockCourse(int fd, int rollNo) {
    struct flock lock;

   
    lock.l_type = F_RDLCK;   
    lock.l_whence = SEEK_SET;
    lock.l_start = COURSE_RECORD_SIZE * (rollNo - 1);
    lock.l_len = COURSE_RECORD_SIZE; 
    lock.l_pid = getpid();   
	printf("locking course\n");
    
    fcntl(fd, F_SETLKW, &lock);
printf("locking course done on rollno:  %d\n",rollNo);
    return 0;
}

void unlockCourse(int fd, int rollNo) {
    struct flock lock;
    lock.l_type = F_UNLCK;   
    lock.l_whence = SEEK_SET;
    lock.l_start = COURSE_RECORD_SIZE * (rollNo - 1);
    lock.l_len = COURSE_RECORD_SIZE;
    lock.l_pid = getpid();
	printf("enter to unlock course \n");
	getchar();	
getchar();

    fcntl(fd, F_SETLK, &lock);
   printf("Process released lock on course %d.\n",  rollNo);
}

void initialize_db2(int fd) {
    lseek(fd, 0, SEEK_SET);
    write(fd, db2, sizeof(db2));
}

int main() {
    int fd;
    int rollNo;
    
   
    fd = open("db2", O_CREAT | O_RDWR, 0744);
   
    if (lseek(fd, 0, SEEK_END) == 0) {
        initialize_db2(fd);
    }

   
    printf("Enter course number (1-%d) to lock: ", 3);
    scanf("%d", &rollNo);

   lockCourse(fd, rollNo);
    lseek(fd, COURSE_RECORD_SIZE * (rollNo - 1), SEEK_SET);
    read(fd, &db2[rollNo - 1], sizeof(db2[0]));

    
    unlockCourse(fd, rollNo);

   

    printf("Roll no: %d\n", db2[rollNo - 1].rollNo);
    printf("Course no: %d\n", db2[rollNo - 1].courseNo);

    close(fd);

    return 0;
}

/*
output:

gitikapinjani@gitikapinjani-Victus-by-HP-Gaming-Laptop-15-fa0xxx:~/HandsOnList1-SS$ cc 18b.c
gitikapinjani@gitikapinjani-Victus-by-HP-Gaming-Laptop-15-fa0xxx:~/HandsOnList1-SS$ ./a.out
Enter course number (1-3) to lock: 1
locking course
locking course done on rollno:  1
enter to unlock course 

Process released lock on course 1.
Roll no: 1
Course no: 0
gitikapinjani@gitikapinjani-Victus-by-HP-Gaming-Laptop-15-fa0xxx:~/HandsOnList1-SS$ 

*/
