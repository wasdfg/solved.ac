#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

vector<int> graph[1001];
vector<bool> visited;

void dfs(int now){
    for(int i = 0;i < graph[now].size();i++){
        if(visited[graph[now][i]] == 0){
            visited[graph[now][i]] = 1;
            cout<<graph[now][i]<<" ";
            dfs(graph[now][i]); 
        }
    }
}


int main(void){
    int n,m,v,a,b;
    cin>>n>>m>>v;
    visited.assign(n+1,0);
    for(int i = 0;i < m;i++){
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i = 1;i < n+1;i++){
        sort(graph[i].begin(),graph[i].end());
    }
    visited[v] = 1;
    cout<<v<<" ";
    dfs(v);
    cout<<"\n";
    visited.assign(n+1,0);
    queue<int> togo;
    togo.push(v);
    visited[v] = 1;
    cout<<v<<" ";
    while(!togo.empty()){
        int now = togo.front();
        togo.pop();
        for(int i = 0;i < graph[now].size();i++){
            if(visited[graph[now][i]] == 0){
                visited[graph[now][i]] = 1;
                cout<<graph[now][i]<<" ";
                togo.push(graph[now][i]);
            }
        }
    }
    return 0;
}