#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

bool cmp(pair<long long,long long> &a,pair<long long,long long> &b){
    if(a.second == b.second){
        return a.first < b.first;
    }
    else{
        return a.second < b.second;
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    long long v,e,a,b,c;
    long long result = 1e+18;
    cin>>v>>e;
    vector<pair<long long,long long>> graph[v+1];
    vector<bool> visited;
    for(int i = 0;i < e;i++){
        cin>>a>>b>>c;
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }
    for(int i = 1;i < v+1;i++){
        sort(graph[i].begin(),graph[i].end(),cmp);
    }
        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>> pq;
        for(int j = 0;j < graph[1].size();j++){
            pq.push({graph[1][j].second,graph[1][j].first});
        }
        visited.assign(v+1,0);
        long long check = 0;
        visited[1] = 1;
        while(!pq.empty()){
            int cost = pq.top().first;
            int now = pq.top().second;
            pq.pop();
            if(visited[now] == 0){
                visited[now] = 1;
                check+=cost;
                for(int j = 0;j < graph[now].size();j++){
                    if(visited[graph[now][j].first] == 0){
                        pq.push({graph[now][j].second,graph[now][j].first});
                    }
                }
            }
        }
        result = min(result,check);
    cout<<result;
    return 0;
}