#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<sys/fcntl.h>
#include<sys/stat.h>
#include<string.h>

int main(){

    char words[300];
    int num, fd ;
    char * myfile="temp/myfile";
    mkfifo(myfile,0666);
   

    printf("Received Messages\n");
    while(1){
        //sleep(5);
        fd= open(myfile,O_RDONLY);
        read(fd,words,300);
        printf("User 1 : %s\n",words);
        close(fd);
    }
    return 0;
}

