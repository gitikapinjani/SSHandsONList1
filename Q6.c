#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main(){
char b[10];
read(0, b, sizeof(b));
write(1,b, sizeof(b));
}
