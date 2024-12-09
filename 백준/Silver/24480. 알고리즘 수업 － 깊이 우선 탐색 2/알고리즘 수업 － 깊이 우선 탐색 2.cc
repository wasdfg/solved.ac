#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<int> graph[100001];
vector<bool> visited(100001,0);
vector<int> order;
int cnt = 1;

void dfs(int now){
    order[now] = cnt;
    for(int i = 0;i < graph[now].size();i++){
        if(visited[graph[now][i]] == 0){
            visited[graph[now][i]] = 1;
            cnt++;
            dfs(graph[now][i]);
        }
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m,r,a,b;
    cin>>n>>m>>r;
    order.assign(n+1,0);
    for(int i = 0;i < m;i++){
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i = 1;i < n+1;i++){
        sort(graph[i].begin(),graph[i].end(),greater<int>());
    }
    visited[r] = 1;
    dfs(r);
    for(int i = 1;i < n+1;i++){
        cout<<order[i]<<"\n";
    }
    return 0;
}