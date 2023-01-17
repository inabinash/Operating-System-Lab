#include<bits/stdc++.h>
#include<unistd.h>
#include<semaphore.h>
#include<pthread.h>
#include<string.h>

using namespace std;
sem_t mut;
int cnt=0;
void* solve(void* args){
    long id ;
    id= (long ) args;
    
      for(int i=0;i<5;i++){
        sem_wait(&mut);
        cout<<"Thread :"<<id<<endl;
        sleep(3);
        sem_post(&mut);
      }
    
}
int main(){
    sem_init(&mut,0,3);
    pthread_t thread1,thread2,thread3,thread4,thread5;
    int p[5]={1,2,3,4,5};
    
    pthread_create(&thread1,NULL,solve, (void*)&p[0]);
    pthread_create(&thread2,NULL,solve,(void*)p[1]);
    pthread_create(&thread3,NULL,solve,(void*)p[2]);
    pthread_create(&thread4,NULL,solve,(void*)p[3]);
    pthread_create(&thread5,NULL,solve,(void*)p[4]);

    pthread_join(thread1,NULL);
    pthread_join(thread2,NULL);
    pthread_join(thread3,NULL);
    pthread_join(thread4,NULL);
    pthread_join(thread5,NULL);
    return 1;

}