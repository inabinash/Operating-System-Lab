// Write a Program to verify that, unlike the other variables of the parent 
// process, a Pipe created by the parent is not copied to its children’s 
// address space; rather it is shared
#include<iostream>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

using namespace std ;
int main(){
    int fd[2];
    
    pipe(fd);
    int p = fork();
    
    if(p>0){
        int a ;cin>>a;
        
        cout<<"Write the value of a into the pipe :"<<a<<endl;
        write(fd[1], &a, sizeof(a));//Write the value of a into the pipe
        close(fd[1]);
        cout<<"Waiting For the Child to Respond"<<endl;
        sleep(2);
        waitpid(p,0,0);
        cout<<"Back to the parent process"<<endl;
        cout<<"Reading to the modified value sent by child"<<endl;
        read(fd[0], &a,sizeof(a));
        close(fd[0]);
        cout<<"Value sent by the child in pipe is :"<<a<<endl;    
    }
    else if(p==0){

        int b;
        cout<<"Will read the value sent by parent"<<endl;
        read(fd[0],&b, sizeof(b));
        close(fd[0]);
        cout<<"Adding 10"<<endl;
        sleep(2);
        b+=10;
        cout<<"Writing back to the parent"<<endl;
        write(fd[1], &b, sizeof(b));
        close(fd[1]);

    }
    return 0;

}