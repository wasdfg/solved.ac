#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N;
vector<vector<int>> togo;
vector<int> visited;

int dfs(int x){
    for(int i = 0;i < togo[x].size();i++){
        if(visited[togo[x][i]] == -1){
            visited[togo[x][i]] = x+1;
            dfs(togo[x][i]);
        }
    }
    return 0;
}

int main(void){
    int a,b;
    cin>>N;
    togo.resize(N,vector<int>());
    visited.resize(N,-1);
    for(int i = 0;i < N-1;i++){
        cin>>a>>b;
        togo[a-1].push_back(b-1);
        togo[b-1].push_back(a-1);
    }
    for(int i = 0;i < N;i++){
        sort(togo[i].begin(),togo[i].end());
    }
    dfs(0);
    for(int i = 1;i < N;i++){
        cout<<visited[i]<<"\n";
    }
    return 0;
}