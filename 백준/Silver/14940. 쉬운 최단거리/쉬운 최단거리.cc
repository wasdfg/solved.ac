#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<vector<int>> bfs;
vector<vector<int>> dp;
queue<pair<int,int>> togo;
int tx[4] = {0,0,-1,1};
int ty[4] = {1,-1,0,0};

int main(void){
    int n,m;
    cin>>n>>m;
    bfs.resize(n,vector<int>(m,0));
    dp.resize(n,vector<int>(m,-1));
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            cin>>bfs[i][j];
            if(bfs[i][j] == 0){
                dp[i][j] = 0;
            }
        }
    }
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            if(bfs[i][j] == 2){
                togo.push({i,j});
                dp[i][j] = 0;
                break;
            }
        }
    }
    while(!togo.empty()){
        int x = togo.front().first;
        int y = togo.front().second;
        togo.pop();
        for(int i = 0;i < 4;i++){
            if(x+tx[i] >= 0 && x+tx[i] < n && y+ty[i] >= 0 && y+ty[i] < m){
                if(bfs[x+tx[i]][y+ty[i]] == 1){
                    bfs[x+tx[i]][y+ty[i]] = 0;
                    dp[x+tx[i]][y+ty[i]] = dp[x][y]+1;
                    togo.push({x+tx[i],y+ty[i]});
                }
            }
        }
    }
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }
}