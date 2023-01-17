// Write a C program to illustrate the use of fork () system call and check 
// if variables in the parent process are shared with child processes or not.


#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(){
    
    int x,y;
    pid_t pid= fork();
    if(pid>0) {
        printf("X :%d  Y: %d \n",x,y);
    }
    else if(pid==0) {
        x=3;y=7;
        printf("X :%d  Y: %d \n",x,y);
       //wait(NULL);
       
    }

    return 0;
}
