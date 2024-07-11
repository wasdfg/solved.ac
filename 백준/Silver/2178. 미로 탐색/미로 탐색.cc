#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(void){
    int n,m;
    cin>>n>>m;
    int dx[4] = {0,0,-1,1};
    int dy[4] = {1,-1,0,0};
    vector<vector<int>> maze(n,vector<int>(m,0));
    vector<vector<int>> dp(n,vector<int>(m,0));
    queue<pair<int,int>> togo;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            scanf("%1d",&maze[i][j]);
        }
    }
    dp[0][0] = 1;
    maze[0][0] = 0;
    togo.push({0,0});
    while(!togo.empty()){
        int x = togo.front().first;
        int y = togo.front().second;
        togo.pop();
        if(x == n-1 && y == m-1){
            break;
        }
        for(int i = 0;i < 4;i++){
            if(x+dx[i] >= 0 && x+dx[i] < n && y+dy[i] >= 0 && y+dy[i] < m && maze[x+dx[i]][y+dy[i]] == 1){
                dp[x+dx[i]][y+dy[i]] = dp[x][y]+1;
                maze[x+dx[i]][y+dy[i]] = 0;
                togo.push({x+dx[i],y+dy[i]});
            }
        }
    }
    cout<<dp[n-1][m-1];
    return 0;
}