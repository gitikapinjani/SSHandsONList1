
/*
======================================================================================== 
Name: 26.c
Author: Gitika Pinjani
Description: Write a program to execute an executable program.
a. use some executable program
b. pass some input to an executable program. (for example execute an executable of $./a.out name)
Date: 31th Aug, 2024
=========================================================================================
*/
#include <stdio.h>
#include <unistd.h>

int main(){

        char* exu_prog = "./Demo26";  
        char* arr[]={exu_prog,"Q26",NULL}; 

        if(execvp(exu_prog,arr)==-1){
                perror("There is an error in executing the program\n");
        }

         return 0;
}

/*
output:

gitikapinjani@gitikapinjani-Victus-by-HP-Gaming-Laptop-15-fa0xxx:~/HandsOnList1-SS$ nano Demo26.c
gitikapinjani@gitikapinjani-Victus-by-HP-Gaming-Laptop-15-fa0xxx:~/HandsOnList1-SS$ cc -o Demo26 Demo26.c
gitikapinjani@gitikapinjani-Victus-by-HP-Gaming-Laptop-15-fa0xxx:~/HandsOnList1-SS$ cc 26.c
gitikapinjani@gitikapinjani-Victus-by-HP-Gaming-Laptop-15-fa0xxx:~/HandsOnList1-SS$ ./a.out
Hello,  Q26.
gitikapinjani@gitikapinjani-Victus-by-HP-Gaming-Laptop-15-fa0xxx:~/HandsOnList1-SS$ 
*/
