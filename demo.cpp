#include<iostream>
#include<sys/unistd.h>
#include<sys/types.h>  //Collection of different typedef and structures like pid_t , u_long , pthread_t 
#include<sys/wait.h>
using namespace std;
int main(){
    char* ptr[]={"ls", NULL};
    cout<<"Before execv function call"<<endl;
    execv(ptr[0],ptr);

    cout<<"Execution Failed"<<endl;
    return 0;
}