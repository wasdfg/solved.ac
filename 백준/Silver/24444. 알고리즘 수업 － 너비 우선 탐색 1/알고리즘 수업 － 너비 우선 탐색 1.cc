#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n,m,r,a,b,cnt = 1;
    cin>>n>>m>>r;
    vector<int> graph[n+1];
    vector<bool> visited(n+1,0);
    vector<int> order(n+1,0);
    for(int i = 0;i < m;i++){
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i = 1;i < n+1;i++){
        sort(graph[i].begin(),graph[i].end());
    }
    order[r] = 1;
    visited[r] = 1;
    queue<int> togo;
    togo.push(r);
    while(!togo.empty()){
        int now = togo.front();
        togo.pop();
        for(int i = 0;i < graph[now].size();i++){
            if(visited[graph[now][i]] == 0){
                visited[graph[now][i]] = 1;
                cnt++;
                order[graph[now][i]] = cnt;
                togo.push(graph[now][i]);
            }
        }
    }
    for(int i = 1;i < n+1;i++){
        cout<<order[i]<<"\n";
    }
    return 0;
}