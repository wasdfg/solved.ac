#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(void){
    int N,M;
    cin>>N>>M;
    vector<vector<int>> maze(N,vector<int>(M,0));
    vector<vector<int>> dp(N,vector<int>(M,0));
    queue<pair<int,int>> togo;
    int tx[4] = {0,0,-1,1};
    int ty[4] = {1,-1,0,0};
    for(int i = 0;i < N;i++){
        for(int j = 0;j < M;j++){
            scanf("%1d",&maze[i][j]);
        }
    }
    maze[0][0] = 0;
    togo.push({0,0});
    dp[0][0]++;
    while(!togo.empty()){
        int x = togo.front().first;
        int y = togo.front().second;
        togo.pop();
        if(x == N -1 && y == M -1){
            break;
        }
        for(int i = 0;i < 4;i++){
            if(x + tx[i] >= 0 && x + tx[i] < N && y + ty[i] >= 0 && y+ty[i] < M){
                if(maze[x + tx[i]][y + ty[i]] == 1){
                    maze[x + tx[i]][y + ty[i]] = 0;
                    togo.push({x + tx[i],y + ty[i]});
                    dp[x + tx[i]][y + ty[i]] = dp[x][y] + 1;
                }
            }
        }
    }
    cout<<dp[N-1][M-1]<<endl;
    return 0;
}