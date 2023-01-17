#include<bits/stdc++.h>
using namespace std;
int main(){
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>>pq; //min heap
    vector<vector<int>>a= {{1,0,5},{2,1,2},{3,2,4},{4,4,3}};    // {burst time ,Process number}
    // First -> Process Number
    //Second -> Arrival Time
    //Third ->  Burst Time
    vector<bool>vis(4,false);
    int time=0;
    int cnt=4;
    while(cnt){
        for(int i=0;i<4;i++){
            //cout<<time<<"   "<<a[i][1]<<endl;
            if(time>=a[i][1]&&vis[i]==false){
                pq.push({a[i][2],a[i][0]});
                vis[i]=true;
            }
        }
         
        int TR;int PI;
        TR=pq.top().first;
        PI=pq.top().second;
        pq.pop();
        cout<<"Process Number :"<<PI<<" with Burst Time "<<TR<<" is executing at time :"<<time<<endl;
        time+=TR;
        cnt--;

    }
}