#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main(){
        int n,fd[2],fd1[2];
        pid_t pid;
        pipe(fd1);
        if(pipe(fd)==-1)exit(1);
        else printf("pipe created by parent successfully\n");
        if((pid=fork())<0)exit(1);
        else if(pid>0){
                int ar[10]={4,3,6,1,2,7,4,9,3,6};


                close(fd[0]);
                write(fd[1],ar,40);
                int ar1[10];
                close(fd1[1]);
                n=read(fd1[0],ar1,40);
                for(int i=0;i<10;i++)
                        printf("%d ",ar1[i]);
        }

else
        {
                int ar[10];
                close(fd[1]);
                n=read(fd[0],ar,40);
                cout<<"n ="<<n<<endl;
                for(int i=0;i<10;i++){
                        //printf("%d ",ar[i]);
                        for(int j=i;j>0;j--){
                                if(ar[j]<ar[j-1]){
                                        int t=ar[j];
                                        ar[j]=ar[j-1];
                                        ar[j-1]=t;
                                }
                        }
                }
                close(fd1[0]);
                write(fd1[1],ar,40);
        }
        return 1;
}