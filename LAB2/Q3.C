#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
int main() {
    int i , j;
    printf("This is the parent process with id %d\n" , getpid());
    printf("Enter thenumber of child processes you wants :");
    int n ;scanf("%d",&n);
    printf("\n");
    for(int i=0;i<n;i++){
        if(fork()==0) {
            printf("Child process %d with id %d \n",i+1 , getpid());
            exit(0);
        }


    }
    for(int j=0;j<n;j++){
        //printf("%d process is waiting\n",getpid());
        wait(NULL);
    }

    return 0;

}