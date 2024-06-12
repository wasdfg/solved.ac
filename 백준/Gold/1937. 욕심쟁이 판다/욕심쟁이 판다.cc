#include<iostream>
#include<vector>

using namespace std;

int n;
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
vector<vector<int>> bamboo;
vector<vector<int>> dp;

int dfs(int x,int y){
    if(dp[x][y] != 0){
        return dp[x][y];
    }
    dp[x][y] = 1;
    for(int i = 0;i < 4;i++){
        if(x+dx[i] >= 0 && x+dx[i] < n && y+dy[i] >= 0 && y+dy[i] < n){
            if(bamboo[x][y] < bamboo[x+dx[i]][y+dy[i]]){
                dp[x][y] = max(dp[x][y],dfs(x+dx[i],y+dy[i])+1);
            }
        }
    }
    return dp[x][y];
}

int main(void){
    int result = 1;
    cin>>n;
    bamboo.assign(n,vector<int>(n,0));
    dp.assign(n,vector<int>(n,0));
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            cin>>bamboo[i][j];
        }
    }
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            result = max(result,dfs(i,j));
        }
    }
    cout<<result;
    return 0;
}