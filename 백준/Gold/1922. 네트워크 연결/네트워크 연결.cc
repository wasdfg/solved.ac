#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int main(void){
    int n,m,a,b,c,result = 0;
    cin>>n>>m;
    vector<pair<int,int>> com[n+1];
    vector<bool> visited(n+1,0);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> togo;
    for(int i = 0;i < m;i++){
        cin>>a>>b>>c;
        if(a != b){
            com[a].push_back({b,c});
            com[b].push_back({a,c});
        }
    }
    togo.push({0,1});
    while(!togo.empty()){
        int cost = togo.top().first;
        int now = togo.top().second;
        togo.pop();
        if(visited[now] == 1){
            continue;
        }
        result+=cost;
        visited[now] = 1;
        for(int i = 0;i < com[now].size();i++){
            if(visited[com[now][i].first] == 0){
                togo.push({com[now][i].second,com[now][i].first});
            }
        }
    }
    cout<<result;
    return 0;
}