#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;
vector<int> chon[101];
vector<int> check(101,0);
vector<bool> visited(101,0);

int n,s,e,m,x,y;

void dfs(int now){
    for(int i = 0;i < chon[now].size();i++){
        if(visited[chon[now][i]] == 0){
            visited[chon[now][i]] = 1;
            check[chon[now][i]] = check[now]+1;
            dfs(chon[now][i]);
        }
    }
}

int main(void){
    cin>>n>>s>>e>>m;
    for(int i = 0;i < m;i++){
        cin>>x>>y;
        chon[x].push_back(y);
        chon[y].push_back(x);
    }
    visited[s] = 1;
    dfs(s);
    if(check[e] != 0){
        cout<<check[e];
    }
    else{
        cout<<"-1";
    }
    return 0;
}