#include<iostream>
#include<vector>
#include<queue>
#include<tuple>

using namespace std;

int main(void){
    int n,m,h,result = 0;
    int dx[6] = {0,0,-1,1,0,0};
    int dy[6] = {1,-1,0,0,0,0};
    int dz[6] = {0,0,0,0,1,-1}; 
    cin>>m>>n>>h;
    int tomato[h][n][m];
    queue<tuple<int,int,int>> togo;
    for(int i = 0;i < h;i++){
        for(int j = 0;j < n;j++){
            for(int k = 0;k < m;k++){
                cin>>tomato[i][j][k];
                if(tomato[i][j][k] == 1){
                    togo.push({i,j,k});
                }
            }
        }
    }
    while(!togo.empty()){
        int x = get<1>(togo.front());
        int y = get<2>(togo.front());
        int z = get<0>(togo.front());
        togo.pop();
        for(int i = 0;i < 6;i++){
            if(x+dx[i] >= 0 && x+dx[i] < n && y+dy[i] >= 0 && y+dy[i] < m && z+dz[i] >= 0 && z+dz[i] < h && tomato[z+dz[i]][x+dx[i]][y+dy[i]] == 0){
                tomato[z+dz[i]][x+dx[i]][y+dy[i]] = tomato[z][x][y]+1;
                togo.push({z+dz[i],x+dx[i],y+dy[i]});
            }
        }
    }
    for(int i = 0;i < h;i++){
        for(int j = 0;j < n;j++){
            for(int k = 0;k < m;k++){
                if(tomato[i][j][k] == 0){
                    cout<<"-1";
                    return 0;
                }
                if(result < tomato[i][j][k]){
                    result = tomato[i][j][k];
                }
            }
        }
    }
    cout<<result-1;
    return 0;
}