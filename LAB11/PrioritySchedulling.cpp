#include<bits/stdc++.h>
using namespace std;
int main(){
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>>pq; //max  heap according to priority
    vector<vector<int>>a= {{1,0,5,5},{2,1,3,8},{3,2,2,1},{4,4,3,6}};    // {burst time ,Process number}
    // First -> Process Number
    //Second -> Arrival Time
    //Third ->  Burst Time
    //Fourth -> Priority
    vector<bool>vis(4,false);
    int time=0;
    int cnt=4;
    while(cnt){
        for(int i=0;i<4;i++){
            //cout<<time<<"   "<<a[i][1]<<endl;
            if(time>=a[i][1]&&vis[i]==false){
                pq.push({a[i][3],{a[i][2],a[i][0]}}); //{PR ,{BT, PI}}
                vis[i]=true;
            }
        }
        int PR , TR , PI;
        PR=pq.top().first;
        TR=pq.top().second.first;
        PI=pq.top().second.second;

        pq.pop();
        cout<<"Process Number :"<<PI<<" with Priority "<<PR<<" is executing at time :"<<time<<endl;
        time+=TR;
        cnt--;
        
    }
}