#include<iostream>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(){
    execl("/bin/ls","ls","-l","-a",NULL);
    printf("Execution Failed");
}