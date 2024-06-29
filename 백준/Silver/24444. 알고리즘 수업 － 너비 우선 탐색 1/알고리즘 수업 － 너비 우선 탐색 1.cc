#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

vector<int> graph[100001];

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m,r,a,b,cnt = 1;
    vector<int> before(100001,0);
    vector<bool> visited(100001,0);
    queue<int> togo;
    cin>>n>>m>>r;
    for(int i = 0;i < m;i++){
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i = 1;i <= n;i++){
        sort(graph[i].begin(),graph[i].end());
    }
    visited[r] = 1;
    before[r] = cnt;
    togo.push(r);
    while(!togo.empty()){
        int x = togo.front();
        togo.pop();
        for(int i = 0;i < graph[x].size();i++){
            if(visited[graph[x][i]] == 0){
                visited[graph[x][i]] = 1;
                cnt++;
                before[graph[x][i]] = cnt;
                togo.push({graph[x][i]});
            }
        }
    }
    for(int i = 1;i <= n;i++){
        cout<<before[i]<<"\n";
    }
    return 0;
}