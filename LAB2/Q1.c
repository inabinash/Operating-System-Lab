#include <stdio.h>
#include <sys/types.h>
#include<sys/wait.h>
#include <unistd.h>
void main() {
 fork();
 fork();
 fork();
 printf("Hello World !\n");
}