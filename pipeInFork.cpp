// C program to illustrate
// pipe system call in C
// shared by Parent and Child
#include<sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include<cstring>
#include <unistd.h>
#include <sys/types.h>
#include<iostream>
using namespace std;

int main(){
    int fd1[2], fd2[2];
    pipe(fd1);
    pipe(fd2);
    int p=fork();
    char fixed[20]="is a good Boy";
    char input_str[100]="Hello";
    
    if(p>0){     //parent class
       //close the reading end of parent
       char concat_str[100];
       close(fd1[0]);
       //write in parent 
       write(fd1[1] , input_str , strlen(input_str)+1);

       close(fd1[1]);
       wait(NULL);

       //read from the child 
       read(fd2[0], concat_str, 100);
       printf("Concanated String is :%s" , concat_str);
       close(fd2[0]);
    }
    else{ //child process
     //close the write end of parent
     char inbuf[100];
     close(fd1[1]);
     read(fd1[0] , inbuf ,100 );
     char concatStr[100];
     int k= strlen(inbuf);
     for(int i=0;i<strlen(fixed);i++){
        concatStr[k++]= fixed[i];
     }
     concatStr[k]='\0';
     // write in parent pipe
     close(fd1[0]);
     close(fd2[0]);
     write(fd2[1] , concatStr,strlen(concatStr)+1);
     close(fd2[1]);
     exit(0);

    }
}