#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>
#include<string.h>
#include<sys/wait.h>
int fd[2];

char line[20];
char result[20];
void chain_of_process(int number,int count,int num){
    if(number<=count){
        num++;
        printf("%d\n",num);
        return;
    }else{
        pipe(fd);
        if(fork()==0){
            close(fd[1]);
            read(fd[0],line,20);
            chain_of_process(number,count+1,atoi(line));
        }else{
           close(fd[0]);
           num++;
           sprintf(result, "%d", num);
            write(fd[1],result,20);
            wait(NULL);
            exit(0);
        }
    }
}
int main(){
    int number,start;
    printf("Enter the number of processes: ");
    scanf("%d",&number);
    printf("Enter the input number: ");
    scanf("%d",&start);
    chain_of_process(number,1,start);
    return 0;
}