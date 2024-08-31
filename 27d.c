/*
========================================================================================
Name: 27c.c
Author: Gitika Pinjani
Description: Write a program to execute ls -Rl by the following system calls
d. execv
Date: 31th Aug, 2024
=========================================================================================
*/
#include<stdio.h>
#include<unistd.h>

int main(){

char *arr[]={"ls","-Rl",NULL};

execv("/bin/ls",arr);
perror("There is an error in executing execlp system call. \n");

return 0;

}
/*
output:
.:
total 256
-rw-rw-r-- 1 gitikapinjani gitikapinjani  1090 Aug 31 01:50 11a.c
-rw-rw-r-- 1 gitikapinjani gitikapinjani  1210 Aug 31 01:54 11b.c
-rw-rw-r-- 1 gitikapinjani gitikapinjani  1142 Aug 31 02:38 11c.c
-rw-rw-r-- 1 gitikapinjani gitikapinjani   745 Aug 31 02:53 12.c
-rw-rw-r-- 1 gitikapinjani gitikapinjani   457 Aug 31 01:03 22.c
-rw-rw-r-- 1 gitikapinjani gitikapinjani   557 Aug 30 17:46 23.c
-rw-rw-r-- 1 gitikapinjani gitikapinjani  1224 Aug 31 01:27 24.c
-rw-rw-r-- 1 gitikapinjani gitikapinjani   598 Aug 30 23:51 25.c
-rw-rw-r-- 1 gitikapinjani gitikapinjani  4409 Aug 31 11:52 27a.c
-rw-rw-r-- 1 gitikapinjani gitikapinjani  4471 Aug 31 12:06 27b.c
-rw-rw-r-- 1 gitikapinjani gitikapinjani  4461 Aug 31 12:14 27c.c
-rw-rw-r-- 1 gitikapinjani gitikapinjani   524 Aug 31 12:20 27d.c
-rw-rw-r-- 1 gitikapinjani gitikapinjani  1738 Aug 30 23:44 28.c
-rw-rw-r-- 1 gitikapinjani gitikapinjani  1769 Aug 31 11:21 29.c
-rw-rw-r-- 1 gitikapinjani gitikapinjani   597 Aug 30 23:46 30.c
-rwxrwxr-x 1 gitikapinjani gitikapinjani 16056 Aug 31 12:20 a.out
-rwxr--r-- 1 gitikapinjani gitikapinjani    41 Aug 31 02:36 cars
-rwxr--r-- 1 gitikapinjani gitikapinjani    18 Aug 11 16:08 cars2
-rwx--x--T 1 gitikapinjani gitikapinjani    30 Aug 30 12:07 fd.txt
-rwxr--r-- 1 gitikapinjani gitikapinjani     4 Aug 22 09:15 file1
-rwxr--r-- 1 gitikapinjani gitikapinjani    50 Aug 22 09:13 file2
-rwxr--r-- 1 gitikapinjani gitikapinjani     0 Aug 11 15:39 file3
-rwxr--r-- 1 gitikapinjani gitikapinjani     0 Aug 11 15:39 file4
-rwxr--r-- 1 gitikapinjani gitikapinjani     0 Aug 11 15:39 file5
-rw-rw-r-- 1 gitikapinjani gitikapinjani    43 Aug 30 10:35 infiniteLoop.c
-rw-rw-r-- 1 gitikapinjani gitikapinjani    64 Aug 31 01:03 output
drwxrwxr-x 3 gitikapinjani gitikapinjani  4096 Aug 22 12:14 Q1
-rw-rw-r-- 1 gitikapinjani gitikapinjani   889 Aug 30 12:06 Q10.c
-rw-rw-r-- 1 gitikapinjani gitikapinjani   660 Aug 30 12:47 Q13.c
-rw-rw-r-- 1 gitikapinjani gitikapinjani   990 Aug 30 16:06 Q14.c
-rw-rw-r-- 1 gitikapinjani gitikapinjani   441 Aug 29 16:36 Q15.c
-rw------- 1 gitikapinjani gitikapinjani    19 Aug 29 17:14 Q16.c.save
-rw-rw-r-- 1 gitikapinjani gitikapinjani   363 Aug 29 22:15 Q19.c
-rw-rw-r-- 1 gitikapinjani gitikapinjani   488 Aug 30 16:17 Q20.c
-rw-rw-r-- 1 gitikapinjani gitikapinjani   221 Aug 30 16:24 Q21.c
-rw-rw-r-- 1 gitikapinjani gitikapinjani    43 Aug  8 14:46 Q2.c
-rw-rw-r-- 1 gitikapinjani gitikapinjani   281 Aug  8 15:44 Q3.c
-rw-rw-r-- 1 gitikapinjani gitikapinjani   136 Aug 11 15:03 Q4.c
-rw-rw-r-- 1 gitikapinjani gitikapinjani   293 Aug 11 15:39 Q5.c
-rw-rw-r-- 1 gitikapinjani gitikapinjani   127 Aug 11 16:00 Q6.c
-rw-rw-r-- 1 gitikapinjani gitikapinjani   480 Aug 22 09:15 Q7.c
-rw-rw-r-- 1 gitikapinjani gitikapinjani    14 Aug 11 16:08 Q7.sh
-rw-rw-r-- 1 gitikapinjani gitikapinjani   584 Aug 30 11:32 Q8.c
-rw-rw-r-- 1 gitikapinjani gitikapinjani   850 Aug 30 11:46 Q9.c
-rw-r--r-- 1 gitikapinjani gitikapinjani 66120 Aug 29 13:22 return

./Q1:
total 40
-rw-rw-r-- 1 gitikapinjani gitikapinjani    97 Aug  8 10:24 1_sftlink.c
-rw-rw-r-- 1 gitikapinjani gitikapinjani    95 Aug  8 10:44 2_hardlink.c
-rw-rw-r-- 1 gitikapinjani gitikapinjani   104 Aug 11 16:54 3_mkfifo.c
-rwxrwxr-x 1 gitikapinjani gitikapinjani 16000 Aug 11 16:57 a.out
drwxrwxr-x 2 gitikapinjani gitikapinjani  4096 Aug 22 16:33 FIFO
-rw-rw-r-- 2 gitikapinjani gitikapinjani    13 Aug  8 10:47 filenew
-rw-rw-r-- 2 gitikapinjani gitikapinjani    13 Aug  8 10:47 hrdlnk
-rwxr--r-- 1 gitikapinjani gitikapinjani     0 Aug 11 16:56 myfifo
lrwxrwxrwx 1 gitikapinjani gitikapinjani     7 Aug  8 10:26 sftln -> filenew

./Q1/FIFO:
total 28
-rwxrwxr-x 1 gitikapinjani gitikapinjani 16184 Aug 22 14:10 a.out
-rw-rw-r-- 1 gitikapinjani gitikapinjani    80 Aug 22 14:10 myfifo
-rw-rw-r-- 1 gitikapinjani gitikapinjani   308 Aug 22 14:09 myfifo1.c
-rw-rw-r-- 1 gitikapinjani gitikapinjani   277 Aug 22 14:10 myfifo2.c
gitikapinjani@gitikapinjani-Victus-by-HP-Gaming-Laptop-15-fa0xxx:~/HandsOnList1-SS$ 
*/
