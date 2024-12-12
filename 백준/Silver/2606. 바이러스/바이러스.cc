#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(void){
    int n,m,a,b,cnt = 0;
    cin>>n>>m;
    vector<int> graph[n+1];
    vector<bool> visited(n+1,0);
    queue<int> togo;
    for(int i = 0;i < m;i++){
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    visited[1] = 1;
    togo.push(1);
    while(!togo.empty()){
        int now = togo.front();
        togo.pop();
        for(int i = 0;i < graph[now].size();i++){
            if(visited[graph[now][i]] == 0){
                visited[graph[now][i]] = 1;
                cnt++;
                togo.push(graph[now][i]);
            }
        }
    }
    cout<<cnt;
    return 0;
}