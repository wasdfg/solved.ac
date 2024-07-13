#include<iostream>
#include<vector>
#include<queue>
#include<tuple>

using namespace std;
int tomato[100][100][100];

int main(void){
    int n,m,h,result = 0;
    int dx[6] = {1,-1,0,0,0,0};
    int dy[6] = {0,0,-1,1,0,0};
    int dz[6] = {0,0,0,0,-1,1};
    queue<tuple<int,int,int>> togo;
    cin>>m>>n>>h;
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
        int x = get<0>(togo.front());
        int y = get<1>(togo.front());
        int z = get<2>(togo.front());
        togo.pop();
        for(int i = 0;i < 6;i++){
            if(x+dx[i] >= 0 && x+dx[i] < h && y+dy[i] >= 0 && y+dy[i] < n && z+dz[i] >= 0 && z+dz[i] < m){
                if(tomato[x+dx[i]][y+dy[i]][z+dz[i]] == 0){
                    tomato[x+dx[i]][y+dy[i]][z+dz[i]] = tomato[x][y][z]+1;
                    togo.push({x+dx[i],y+dy[i],z+dz[i]});
                }
            } 
        }
    }
    bool cant = false;
    for(int i = 0;i < h;i++){
        for(int j = 0;j < n;j++){
            for(int k = 0;k < m;k++){
                if(tomato[i][j][k] == 0){
                    cant = true;
                    break;
                }
                result = max(result,tomato[i][j][k]);
            }
        }
    }
    if(cant == 1){
        cout<<"-1";
    }
    else{
        cout<<result-1;
    }
    return 0;
}