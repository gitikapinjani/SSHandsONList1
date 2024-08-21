#include<stdio.h>
#include<unistd.h>
int main(){
link("filenew","hrdlnk");

perror("error");
}
