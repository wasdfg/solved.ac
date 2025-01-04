#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int main(void){
    int n,m,u,v,count = 0;
    cin>>n>>m;
    vector<int> graph[n+1];
    vector<bool> visited(n+1,0);
    queue<int> togo;
    for(int i = 0;i < m;i++){
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for(int i = 1;i < n+1;i++){
        if(visited[i] == 0){
            visited[i] = 1;
            togo.push(i);
            count++;
        }
        while(!togo.empty()){
            int now = togo.front();
            togo.pop();
            for(int j = 0;j < graph[now].size();j++){
                if(visited[graph[now][j]] == 0){
                    visited[graph[now][j]] = 1;
                    togo.push(graph[now][j]);
                }
            }
        } 
    }
    cout<<count;
    return 0;
}