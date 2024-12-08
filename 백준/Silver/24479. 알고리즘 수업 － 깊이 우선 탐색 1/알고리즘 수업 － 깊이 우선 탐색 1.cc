#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n,check = 1;
vector<int> graph[100001];
vector<bool> visited(100001,0);
vector<int> order;

void dfs(int now){
    for(int i = 0;i < graph[now].size();i++){
        if(visited[graph[now][i]] == 0){
            visited[graph[now][i]] = 1;
            check++;
            order[graph[now][i]] = check;
            dfs(graph[now][i]);
        }
    }
}

int main(void){
    int m,r,a,b;
    cin>>n>>m>>r;
    order.assign(n+1,0);
    for(int i = 0;i < m;i++){
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i = 1;i < n+1;i++){
        sort(graph[i].begin(),graph[i].end());
    }
    visited[r] = 1;
    order[r] = check;
    dfs(r);
    for(int i = 1;i < n+1;i++){
        cout<<order[i]<<"\n";
    }
    return 0;
}