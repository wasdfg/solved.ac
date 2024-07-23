#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<bool> visited(100002,0);

int main(void){
    int n,k,result;
    cin>>n>>k;
    priority_queue<pair<int,int>> togo;
    visited[n] = 1;
    togo.push({0,n});
    while(!togo.empty()){
        int now = togo.top().second;
        int cost = -togo.top().first;
        togo.pop();
        if(now == k){
            result = cost;
            break;
        }
        visited[now] = 1;
        if(now*2 < 100002 && visited[now*2] == 0){
            togo.push({-cost,now*2});
        }
        if(now-1 >= 0 && visited[now-1] == 0){
            togo.push({-(cost+1),now-1});
        }
        if(now+1 < 100002 && visited[now+1] == 0){
            togo.push({-(cost+1),now+1});
        }
    }
    cout<<result;
    return 0;
}