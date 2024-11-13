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
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,1});
    while(!pq.empty()){
        int now = pq.top().second;
        int cost = pq.top().first;
        pq.pop();
        if(visited[now] == 1){
            continue;
        }
        visited[now] = 1;
        result+=cost;
        if(cost > check){
            check = cost;
        }
        for(int i = 0;i < home[now].size();i++){
            if(visited[home[now][i].first] == 0){
                pq.push({home[now][i].second,home[now][i].first});
            }
        }
    }
    cout<<result-check;
    return 0;
}