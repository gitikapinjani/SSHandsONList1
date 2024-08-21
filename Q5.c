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
