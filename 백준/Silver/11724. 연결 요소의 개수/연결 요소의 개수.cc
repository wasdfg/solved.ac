#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<vector<int>> graph;
vector<bool> visited;

int dfs(int x){
    visited[x] = 1;
    for(int i = 0;i < graph[x].size();i++){
        if(visited[graph[x][i]] == 0){
            dfs(graph[x][i]);
        }
    }
    return 0;
}

int main(void){
    int N,M,a,b,count = 0;
    cin>>N>>M;
    graph.resize(N);
    visited.resize(N);
    for(int i = 0;i < M;i++){
        cin>>a>>b;
        graph[a-1].push_back(b-1);
        graph[b-1].push_back(a-1);
    }
    for(int i = 0;i < N;i++){
        stable_sort(graph[i].begin(),graph[i].end());
    }
    for(int i = 0;i < N;i++){
        if(visited[i] == 0){
            dfs(i);
            count++;
        }
    }
    cout<<count<<endl;
}