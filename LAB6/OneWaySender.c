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
    mkfifo("myfile.txt",0666);

    fd= open("myfile.txt", O_WRONLY);
    printf("This is the Sender End \n Send some sentences as messages  :\n");
    while(1){
        fgets(words,300,stdin);
        if(words[0]=="\0") break;
        write(fd , words, strlen(words));

    }
    printf("All messages sent.\n");
    return 0;
}

