#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(void){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> zido(n,vector<int>(m,0));
    vector<vector<bool>> visited(n,vector<bool>(m,0));
    queue<pair<int,int>> togo;
    int dx[4] = {0,0,-1,1};
    int dy[4] = {1,-1,0,0};
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            cin>>zido[i][j];
            if(zido[i][j] == 2){
                togo.push({i,j});
                visited[i][j] = 1;
                zido[i][j] = 1;
            }
        }
    }
    while(!togo.empty()){
        int x = togo.front().first;
        int y = togo.front().second;
        togo.pop();
        for(int i = 0;i < 4;i++){
            if(x+dx[i] >= 0 && x+dx[i] < n && y+dy[i] >= 0 && y+dy[i] < m && visited[x+dx[i]][y+dy[i]] == 0 && zido[x+dx[i]][y+dy[i]] == 1){
                visited[x+dx[i]][y+dy[i]] = 1;
                zido[x+dx[i]][y+dy[i]] = zido[x][y]+1;
                togo.push({x+dx[i],y+dy[i]});
            }
        }
    }
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            if(zido[i][j] != 0 && visited[i][j] == 1){
                cout<<zido[i][j]-1<<" ";
            }
            else if(zido[i][j] == 0){
                cout<<"0 ";
            }
            else if(zido[i][j] == 1 && visited[i][j] == 0){
                cout<<"-1 ";
            }
        }
        cout<<endl;
    }
    return 0;
}