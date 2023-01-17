#include <iostream>
#include <thread>
#include <unistd.h>
#include<mutex>


using namespace std;

int cond=condition();
int done=1;
void task(string name){
      while(cond){
        if(done==1){
            done=2;
            count<<"Waiting on conditional variable cond :"<<name<<endl;
            count<<"Condition met"<<name<<endl;
        }

        else {
            for(int i=0;i<5;i++){
                cout<<"Hello"<<end;
            }
            cout<<"Signalling Conditinal Varriable cond :" <<name<<endl;
            
        }
      }
}
int main(){
    thread t1(task);
    thread t2(task);

    t1.join();
    t2.join();

}

