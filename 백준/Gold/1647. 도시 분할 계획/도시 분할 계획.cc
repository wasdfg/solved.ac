#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(void){
    int n,m,a,b,c,result = 0,check = 0;
    cin>>n>>m;
    vector<pair<int,int>> home[n+1];
    vector<bool> visited(n+1,0);
    for(int i = 0;i < m;i++){
        cin>>a>>b>>c;
        home[a].push_back({b,c});
        home[b].push_back({a,c});
    }
    visited[1] = 1;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    for(int i = 0;i < home[1].size();i++){
        pq.push({home[1][i].second,home[1][i].first});
    }
    while(!pq.empty()){
        int now = pq.top().second;
        int cost = pq.top().first;
        pq.pop();
        if(visited[now] == 0){
            visited[now] = 1;
            result+=cost;
            check = max(check,cost);
            for(int i = 0;i < home[now].size();i++){
                if(visited[home[now][i].first] == 0){
                    pq.push({home[now][i].second,home[now][i].first});
                }
            }
        }
    }
    cout<<result-check;
    return 0;
}