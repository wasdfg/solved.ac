#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(void){
    vector<bool> visited(200001,0);
    queue<pair<int,int>> togo;
    int s,e,count = 0,check = 0;
    cin>>s>>e;
    togo.push({s,0});
    visited[s] = 1;
    while(!togo.empty()){
        int now = togo.front().first;
        int cost = togo.front().second;
        togo.pop();
        visited[now] = 1;
        if(now == e){
            if(count != 0 && cost == count){
                check++;
            }
            if(count == 0){
                count = cost;
                check = 1;
            }
        }
        if(now + 1 <= 100000 && visited[now+1] == 0){
            togo.push({now+1,cost+1});
        }
        if(now - 1 >= 0 && visited[now-1] == 0){
            togo.push({now-1,cost+1});
        }
        if(now * 2 <= 100000 && visited[now*2] == 0){
            togo.push({now*2,cost+1});
        }
    }
    cout<<count<<"\n"<<check;
    return 0;
}