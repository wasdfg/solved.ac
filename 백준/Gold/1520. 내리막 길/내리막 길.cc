#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int n,m,count = 0;
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
vector<vector<int>> board;
vector<vector<int>> dp;

int dfs(int x,int y){
    if(x == m-1 && y == n-1){
        return 1;
    }
    if(dp[x][y] == -1){
        dp[x][y] = 0;
        for(int i = 0;i < 4;i++){
            if(x+dx[i] >= 0 && x+dx[i] < m && y+dy[i] >= 0 && y+dy[i] < n){
                if(board[x+dx[i]][y+dy[i]] < board[x][y]){
                    dp[x][y]+=dfs(x+dx[i],y+dy[i]);
                }
            }
        }
    }
    return dp[x][y];
}

int main(void){
    cin>>m>>n;
    board.assign(m,vector<int>(n,0));
    dp.assign(m,vector<int>(n,-1));
    for(int i = 0;i < m;i++){
        for(int j = 0;j < n;j++){
            cin>>board[i][j];
        }
    }
    cout<<dfs(0,0);
    return 0;
}