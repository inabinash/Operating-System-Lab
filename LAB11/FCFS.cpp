#include<bits/stdc++.h>
using namespace std;
int main(){
    queue<pair<int,pair<int,int>>>q; //{Time Reamining , Index}
    vector<vector<int>>a= {{1,0,5},{2,1,3},{3,2,2},{4,4,3}};    // {burst time ,Process number}
    // First -> Process Number
    //Second -> Arrival Time
    //Third ->  Burst Time
    //sort()
    vector<bool>vis(4,false);
    int time=0;
    int cnt=4;
    
    while(cnt){
        for(int i=0;i<4;i++){
            //cout<<time<<"   "<<a[i][1]<<endl;
            if(time>=a[i][1]&&vis[i]==false){
                q.push({a[i][2],{a[i][0], a[i][1]}});
                vis[i]=true;
            }
        }
        int TR;int PI;
        TR=q.front().first;
        PI=q.front().second.first;
        int AT= q.front().second.second;
        q.pop();
        cout<<"Process P"<<PI<<" is executed at time :"<<time<<" Arriving at "<<AT<<endl;
        time+=TR;
        //cout<<time<<endl;
         cnt--;

        
        
    }
}