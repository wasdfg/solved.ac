#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int main(void){
    int n,m,a,b,count = 0;
    vector<int> graph[101];
    vector<bool> visited(101,0);
    queue<int> togo;
    cin>>n>>m;
    for(int i = 0;i < m;i++){
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    togo.push(1);
    visited[1] = 1;
    while(!togo.empty()){
        int now  = togo.front();
        togo.pop();
        for(int i = 0;i < graph[now].size();i++){
            if(visited[graph[now][i]] == 0){
                visited[graph[now][i]] = 1;
                count++;
                togo.push(graph[now][i]);
            }
        }
    }
    cout<<count;
    return 0;
}