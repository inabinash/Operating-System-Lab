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
    int fd;
    char * myfile="temp/myfile";

    mkfifo(myfile,0666);

    fd= open(myfile, O_WRONLY);
    printf("This is the Sender End \n Send some sentences as messages  :\n");
    while(1){
        fd =open(myfile,O_WRONLY);
        fgets(words, 300, stdin);
        write(fd,words,strlen(words)+1);
        close(fd);

    }
   
    return 0;
}

