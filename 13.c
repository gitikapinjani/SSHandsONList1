/*
======================================================================================== 
Name: 13.c
Author: Gitika Pinjani
Description: Write a program to wait for a STDIN for 10 seconds using select. Write a proper print statement to
verify whether the data is available within 10 seconds or not (check in $man 2 select).
Date: 28th Aug, 2024
=========================================================================================
*/
#include <sys/types.h>
#include <sys/time.h>
#include <err.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(void)
{
    struct timeval tmo;
    fd_set readfds;

    FD_ZERO(&readfds);
    FD_SET(STDIN_FILENO, &readfds);
    tmo.tv_sec = 10;
    printf("waiting for input for 10 sec. ");
    int value = select(STDIN_FILENO+1, &readfds, NULL, NULL, &tmo);
    if(value== -1)
        printf("error in select function.");
    else if(value ==0)
        printf("User don't give input");  
    else{
if(FD_ISSET(STDIN_FILENO, &readfds)){
        printf("User has input a number.");}
}
    return (0);
}

/*
output: 

gitikapinjani@gitikapinjani-Victus-by-HP-Gaming-Laptop-15-fa0xxx:~/HandsOnList1-SS$ cc 13.c
gitikapinjani@gitikapinjani-Victus-by-HP-Gaming-Laptop-15-fa0xxx:~/HandsOnList1-SS$ ./a.out
w
waiting for input for 10 sec. User has input a number.
gitikapinjani@gitikapinjani-Victus-by-HP-Gaming-Laptop-15-fa0xxx:~/HandsOnList1-SS$ 
*/
