#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(void){
    int t,n,m,k,a,b,count;
    vector<vector<int>> bachu;
    vector<vector<bool>> visited;
    int dx[4] = {0,0,-1,1};
    int dy[4] = {1,-1,0,0};
    cin>>t;
    for(int i = 0;i < t;i++){
        cin>>m>>n>>k;
        count = 0;
        bachu.assign(n,vector<int>(m,0));
        visited.assign(n,vector<bool>(m,0));
        queue<pair<int,int>> togo;
        for(int j = 0;j < k;j++){
            cin>>a>>b;
            bachu[b][a] = 1;
        }
        for(int s = 0;s < n;s++){
            for(int t = 0;t < m;t++){
                if(bachu[s][t] == 1 && visited[s][t] == 0){
                    visited[s][t] = 1;
                    togo.push({s,t});
                    while(!togo.empty()){
                        int x = togo.front().first;
                        int y = togo.front().second;
                        togo.pop();
                        for(int u = 0;u < 4;u++){
                            if(x+dx[u] >= 0 && x+dx[u] < n && y+dy[u] >= 0 && y+dy[u] < m && bachu[x+dx[u]][y+dy[u]] == 1 && visited[x+dx[u]][y+dy[u]] == 0){
                                visited[x+dx[u]][y+dy[u]] = 1;
                                togo.push({x+dx[u],y+dy[u]});
                            }
                        }
                    }
                    count++;
                }
            }
        }
        cout<<count<<endl;
    }
    return 0;
}