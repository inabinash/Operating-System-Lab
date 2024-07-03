// Round Robin with Time Quantum
#include<bits/stdc++.h>
using namespace std;
int main(){
    queue<pair<int,int>>q; //{Time Reamining , Index}
    vector<vector<int>>a= {{1,0,5},{2,1,3},{3,2,2},{4,4,3}};    // {burst time ,Process number}
    // First -> Process Number
    //Second -> Arrival Time
    //Third ->  Burst Time
    vector<bool>vis(4,false);
    int time=0;
    int cnt=4;
    int tq=1;
    while(cnt){
        for(int i=0;i<4;i++){
            //cout<<time<<"   "<<a[i][1]<<endl;
            if(time>=a[i][1]&&vis[i]==false){
                q.push({a[i][2],a[i][0]});
                vis[i]=true;
            }
        }
        int TR;int PI;
        TR=q.front().first;
        PI=q.front().second;
        q.pop();
        int timeConsumed=0;
        timeConsumed=min(tq,TR);
        time+=timeConsumed;
        //cout<<time<<endl;
        cout<<"Process Number :"<<PI<<" is executing and The Remaining Time is :"<<TR<<" Time Quantum is :"<<tq<<endl;
        TR-=timeConsumed;
        if(TR>0){
            q.push({TR,PI});
        }
        else cnt--;
        //Doubling The Time Quantum
        tq=tq*2;
    }
}
