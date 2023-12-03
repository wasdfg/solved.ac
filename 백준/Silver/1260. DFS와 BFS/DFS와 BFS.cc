#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

vector<int> vertex[1002];
vector<bool> visited(1002,false);
vector<int> bfs[1002];
vector<int> dfs[1002];

int BFS(int start){
    queue<int> togo;
    togo.push(start);
    visited[start] = true;
    while(!togo.empty()){
        int x = togo.front();
        cout<<x<<" ";
        togo.pop();
        for(int i = 0;i < bfs[x].size();i++){
            if(!visited[bfs[x][i]]){
                togo.push(bfs[x][i]);
                visited[bfs[x][i]] = true;
            }
        }
    }
    return 0;
}

int DFS(int start){
    visited[start] = true;
    cout<<start<<" ";
    for(int i = 0;i < dfs[start].size();i++){
        if(!visited[dfs[start][i]]){
            DFS(dfs[start][i]);
        }
    }
    return 0;
}

int main(void){
    int dot,line,start,a,b;
    scanf("%d %d %d",&dot,&line,&start);
    for(int i = 0;i < line;i++){
        scanf("%d %d",&a,&b);
        bfs[a].push_back(b);
        bfs[b].push_back(a);
        dfs[a].push_back(b);
        dfs[b].push_back(a);
    }
    for(int i = 1;i < 1002;i++){
        stable_sort(bfs[i].begin(),bfs[i].end());
        stable_sort(dfs[i].begin(),dfs[i].end());
    }
    DFS(start);
    cout<<"\n";
    for(int i = 0;i < 1002;i++){
        visited[i] = false;
    }
    BFS(start);
    cout<<"\n";
    return 0;
}