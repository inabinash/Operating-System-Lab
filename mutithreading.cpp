#include <iostream>
#include <thread>
#include <unistd.h>

#include<mutex>
using namespace std;

mutex foo ,bar;
void taskA(){
    lock(foo,bar);
    for(int i=0;i<10;i++){
        
        cout<<"TaskA :"<<i<<endl;
        fflush(stdout);
    }
    foo.unlock();
    bar.unlock();
}

void taskB(){
    lock(bar, foo);
    for(int i=0;i<10;i++){
       
        cout<<"TaskB :"<<i<<endl;
        fflush(stdout);
    }
    bar.unlock();
    foo.unlock();
    
}


int main(){
    thread t1(taskA);
    thread t2(taskB);
    t1.join();
    t2.join();
    return 0;
}