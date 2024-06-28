#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<int> dot[100001];
vector<bool> visited(100001,0);
vector<int> before(100001,0);
int cnt = 1;

void dfs(int start,int x){
    visited[start] = 1;
    x = cnt;
    before[start] = x;
    for(int i = 0;i < dot[start].size();i++){
        if(visited[dot[start][i]] == 0){
            cnt+=1;
            dfs(dot[start][i],cnt);
        }
    }
}

int main(void){
    int n,m,r,a,b;
    cin>>n>>m>>r;
    for(int i = 0;i < m;i++){
        cin>>a>>b;
        dot[a].push_back(b);
        dot[b].push_back(a);
    }
    for(int i = 1;i <= n;i++){
        sort(dot[i].begin(),dot[i].end());
    }
    dfs(r,cnt);
    for(int i = 1;i <= n;i++){
        cout<<before[i]<<"\n";
    }
    return 0;
}