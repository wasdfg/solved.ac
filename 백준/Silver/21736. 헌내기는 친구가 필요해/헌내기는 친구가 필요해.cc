#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(void){
    int n,m,count = 0;
    int dx[4] = {0,0,-1,1};
    int dy[4] = {1,-1,0,0};
    char point;
    cin>>n>>m;
    vector<vector<int>> campus(n,vector<int>(m,0));
    vector<vector<bool>> visited(n,vector<bool>(m,0));
    queue<pair<int,int>> togo;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            cin>>point;
            if(point == 'O'){
                campus[i][j] = 0;
            }
            if(point == 'X'){
                campus[i][j] = -1;
            }
            if(point == 'I'){
                campus[i][j] = 0;
                togo.push({i,j});
                visited[i][j] = 1; 
            }
            if(point == 'P'){
                campus[i][j] = 1;
            }
        }
    }
    while(!togo.empty()){
        int x = togo.front().first;
        int y = togo.front().second;
        togo.pop();
        for(int i = 0;i < 4;i++){
            if(x+dx[i] >= 0 && x+dx[i] < n && y+dy[i] >= 0 && y+dy[i] < m && campus[x+dx[i]][y+dy[i]] >= 0 && visited[x+dx[i]][y+dy[i]] == 0){
                if(campus[x+dx[i]][y+dy[i]] == 1){
                    count++;
                }
                visited[x+dx[i]][y+dy[i]] = 1;
                togo.push({x+dx[i],y+dy[i]});
            }
        }
    }
    if(count == 0){
        cout<<"TT";
    }
    else{
        cout<<count;
    }
    return 0;
}