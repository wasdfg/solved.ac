#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<int> graph[100001];
vector<bool> visited(100001,0);
vector<int> before(100001,0);
int cnt = 1;

void dfs(int x,int check){
    visited[x] = 1;
    check = cnt;
    before[x] = check;
    for(int i = 0;i < graph[x].size();i++){
        if(visited[graph[x][i]] == 0){
            cnt++;
            dfs(graph[x][i],cnt);
        }
    }
}

int main(void){
    int n,m,r,a,b;
    cin>>n>>m>>r;
    for(int i = 0;i < m;i++){
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i = 1;i <= n;i++){
        sort(graph[i].begin(),graph[i].end(),greater<int>());
    }
    dfs(r,cnt);
    for(int i = 1;i <= n;i++){
        cout<<before[i]<<"\n";
    }
    return 0;
}