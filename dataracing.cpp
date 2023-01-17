#include<iostream>
#include<thread>



using namespace std;

int count=0;
void taskA(){
    for(int i=0;i<100000;i++){
        int temp = count+1;
        count=temp;
        
    }
}

void taskB(){
    for(int i=0;i<10;i++){
        //sleep(1);
        cout<<"TaskB :"<<i<<endl;
        fflush(stdout);
    }
}


int main(){
    thread t1(taskA);
    thread t2(taskA);
    t1.join();
    t2.join();
    cout<<count<<endl;
    return 0;
}