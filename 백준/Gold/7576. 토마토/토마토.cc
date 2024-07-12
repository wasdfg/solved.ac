#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(void){
    int n,m,result = 0;
    cin>>m>>n;
    vector<vector<int>> tomato(n,vector<int>(m,0));
    queue<pair<int,int>> togo;
    int dx[4] = {0,0,-1,1};
    int dy[4] = {1,-1,0,0};
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            cin>>tomato[i][j];
            if(tomato[i][j] == 1){
                togo.push({i,j});
            }
        }
    }
    while(!togo.empty()){
        int x = togo.front().first;
        int y = togo.front().second;
        togo.pop();
        for(int i = 0;i < 4;i++){
            if(x+dx[i] >= 0 && x+dx[i] < n && y+dy[i] >= 0 && y+dy[i] < m && tomato[x+dx[i]][y+dy[i]] == 0){
                tomato[x+dx[i]][y+dy[i]] = tomato[x][y]+1;
                result = max(result,tomato[x+dx[i]][y+dy[i]]);
                togo.push({x+dx[i],y+dy[i]});
            }
        }
    }
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            if(tomato[i][j] == 0){
                cout<<"-1";
                return 0;
            }
        }
    }
    cout<<(result > 0?result-1:0);
    return 0;
}