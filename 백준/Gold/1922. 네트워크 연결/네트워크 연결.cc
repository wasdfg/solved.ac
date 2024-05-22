#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

int main(void){
    int n,m,a,b,c,result = 0;
    cin>>n>>m;
    vector<pair<int,int>> com[n+1];
    vector<bool> visited(n+1,0);
    for(int i = 0;i < m;i++){
        cin>>a>>b>>c;
        if(a != b){
            com[a].push_back({b,c});
            com[b].push_back({a,c});
        }
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    for(int i = 0;i < com[1].size();i++){
        pq.push({com[1][i].second,com[1][i].first});
    }
    visited[1] = 1;
    while(!pq.empty()){
        int cost = pq.top().first;
        int now = pq.top().second;
        pq.pop();
        if(visited[now] == 0){
            visited[now] = 1;
            result += cost; 
            for(int i = 0;i < com[now].size();i++){
                if(visited[com[now][i].first] == 0){
                    pq.push({com[now][i].second,com[now][i].first});
                }
            }
        }
    }
    cout<<result;
    return 0;
}