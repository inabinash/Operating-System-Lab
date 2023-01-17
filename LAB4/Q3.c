#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(){
    int n ;
    scanf("%d" , &n);
    printf("Main process Id :%d\n",getpid());
    for(int i=0;i<n;i++){
        pid_t p = fork();
        if(p>0) {
            wait(NULL);
            //printf("I am breaking %d\n", getpid());
            break ;
        }
        else if(p==0){
            printf("Parent id %d Child Id %d\n", getppid(),getpid());

        }
        else{
            printf("Fork incomplete");
        }
    }
}