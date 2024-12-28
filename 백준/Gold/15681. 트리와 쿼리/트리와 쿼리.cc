#include<iostream>
#include<vector>

using namespace std;

vector<int> tree[100001];
vector<int> dp;
vector<bool> visited;

void dfs(int now,int parent){
    for(int i = 0;i < tree[now].size();i++){
        if(visited[tree[now][i]] == 0){
            visited[tree[now][i]] = 1;
            dfs(tree[now][i],now);
        }
    }
    if(parent != -1){
        dp[parent]+=dp[now];
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,r,q,u,v;
    cin>>n>>r>>q;
    dp.assign(n+1,1);
    visited.assign(n+1,0);
    for(int i = 0;i < n-1;i++){
        cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    visited[r] = 1;
    dfs(r,-1);
    for(int i = 0;i < q;i++){
        cin>>u;
        cout<<dp[u]<<"\n";
    }
    return 0;
}