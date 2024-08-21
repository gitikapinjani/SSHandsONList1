#include<stdio.h>
#include <sys/stat.h>
int main (){
mknod("myfifo",0744,0);
perror("error occured");
}
