#include<iostream>
#include<vector>
#include<deque>

using namespace std;

int main(void){
    int n,result = 2501;
    int dx[4] = {0,0,-1,1};
    int dy[4] = {1,-1,0,0};
    cin>>n;
    vector<vector<int>> maze(n,vector<int>(n,0));
    vector<vector<int>> dp(n,vector<int>(n,2501));
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            scanf("%1d",&maze[i][j]);
        }
    }
    deque<pair<int,int>> togo;
    togo.push_front({0,0});
    dp[0][0] = 0;
    while(!togo.empty()){
        int x = togo.front().first;
        int y = togo.front().second;
        togo.pop_front();
        if(x == n-1 && y == n-1){
            result = min(dp[n-1][n-1],result);
        }
        for(int i = 0;i < 4;i++){
            if(x+dx[i] >= 0 && x+dx[i] < n && y+dy[i] >= 0 && y+dy[i] < n && dp[x+dx[i]][y+dy[i]] == 2501){
                if(maze[x+dx[i]][y+dy[i]] == 1){
                    dp[x+dx[i]][y+dy[i]] = dp[x][y];
                    togo.push_front({x+dx[i],y+dy[i]});
                }
                else{
                    dp[x+dx[i]][y+dy[i]] = dp[x][y]+1;
                    togo.push_back({x+dx[i],y+dy[i]});
                }      
            }
        }
    }
    cout<<result;
    return 0;
}