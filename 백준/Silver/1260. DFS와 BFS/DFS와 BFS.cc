#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

vector<int> vertex[1001];
vector<bool> visited(1001,0);
vector<int> dfs;
vector<int> bfs;

int BFS(int start){
    queue<int> togo;
    togo.push(start);
    visited[start] = 1;
    while(!togo.empty()){
        int x = togo.front();
        cout<<x<<" ";
        togo.pop();
        for(int i = 0;i < vertex[x].size();i++){
            if(!visited[vertex[x][i]]){
                togo.push(vertex[x][i]);
                visited[vertex[x][i]] = 1;
            }
        }
    }
    return 0;
}

int DFS(int start){
    visited[start] = 1;
    cout<<start<<" ";
    for(int i = 0;i < vertex[start].size();i++){
        if(!visited[vertex[start][i]]){
            DFS(vertex[start][i]);
        }
    }
    return 0;
}

int main(void){
    int dot,line,start,a,b;
    cin>>dot>>line>>start;
    for(int i = 0;i < line;i++){
        cin>>a>>b;
        vertex[a].push_back(b);
        vertex[b].push_back(a);
    }
    for(int i = 1;i < 1001;i++){
        sort(vertex[i].begin(),vertex[i].end());
    }
    DFS(start);
    cout<<"\n";
    visited.assign(1001,0);
    BFS(start);
    cout<<"\n";
    return 0;
}