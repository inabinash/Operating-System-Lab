#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(){
    int d , n ;
    printf("Enter the depth and Degree :");
    scanf("%d %d",&d,&n);
    l:
    if(d==0) {
        //printf("Process Id %d:\n",getpid());
        return 0;
    }
    for(int i=0;i<n;i++){
        pid_t p=fork();
        pid_t par = getppid();
        pid_t ch = getpid();
        //printf("Parent %d  Child %d" , par , ch);

        if(p>0){
            waitpid(p,0,0);
        }
        else {
            printf("Parent : %d Child : %d\n",par , ch);
            d--;
            goto l ;
        }
    }
}