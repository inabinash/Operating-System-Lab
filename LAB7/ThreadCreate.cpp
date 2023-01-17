#include<pthread.h>
#include<iostream>
#include<sys/types.h>
using namespace std;
int val=0;
void* solve(void * args){

    pid_t p= pthread_self();
    
    //pthread_t id = *(int *)args;
    //cout<<"Thead running :"<<id<<endl;
    for(int i=0;i<100;i++){
        cout<<p<<endl;
        int temp=val;
        temp=temp+1;
        val=temp;
    }
}
int main(){
   pthread_t p1,p2;
   pthread_create(&p1,NULL,&solve,NULL);
   pthread_create(&p2,NULL,&solve,NULL);

  pthread_join(p1, NULL);
  pthread_join(p2,NULL);
   
   cout<<"Value of val is :"<<val<<endl;
   return 0;
}