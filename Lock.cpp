#include<iostream>
#include<thread>

#include<unistd.h>

using namespace std;
int ans=0;
int count=0;int turn=0;
void taskA(int turn ){
    while(turn!=0);
    for(int i=0;i<10;i++){
        count+=1;
        cout<<count<<" :A"<<endl;
    }
    turn =1;
}

void taskB(int turn){
   if(turn==1){
        for(int i=0;i<10;i++){
        count+=1;
        cout<<count<<": B"<<endl;
    }
    turn=0;
   }
     
}



int main(){
    
    thread t1(taskA, turn  );
    thread t2(taskB , turn);
    t1.join();
    t2.join();
    cout<<count<<endl;
    return 0;
}