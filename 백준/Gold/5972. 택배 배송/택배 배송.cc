#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(void){
    int n,m,a,b,c;
    cin>>n>>m;
    vector<pair<int,long long>> graph[n+1];
    
    for(int i = 0;i < m;i++){
        cin>>a>>b>>c;
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }
    vector<long long> need(n+1,2500000000001);
    priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> togo;
    togo.push({0,1});
    need[1] = 0;
    while(!togo.empty()){
        int now = togo.top().second;
        long long cost = togo.top().first;
        togo.pop();
        if(need[now] < cost){
            continue;
        }
        for(int i = 0;i < graph[now].size();i++){
            int next = graph[now][i].first;
            long long ncost = graph[now][i].second;
            if(cost+ncost < need[next]){
                need[next] = cost+ncost;
                togo.push({cost+ncost,next});
            }
        }
    }
    cout<<need[n];
    return 0;
}