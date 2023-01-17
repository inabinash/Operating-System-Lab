#include <iostream>
#include <thread>
#include <unistd.h>

#include<mutex>
using namespace std;
condition()
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
int count=0;
void task(){
    foo.lock();
    for(int i=0;i<1000;i++){
        count+=1;
    }
    foo.unlock();
}

int main(){
    // thread t1(taskA);
    // thread t2(taskB);
    thread t3(task);
    thread t4(task);
    t3.join();
    t4.join();
    //t1.join();
    //t2.join();
    cout<<count<<endl;
    return 0;
}