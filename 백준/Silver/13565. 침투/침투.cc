#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int m,n;
bool noelec = true;
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
vector<vector<int>> perc;
vector<vector<bool>> visited;

void dfs(int x,int y){
    for(int i = 0;i < 4;i++){
        if(x+dx[i] >= 0 && x+dx[i] < m && y+dy[i] >= 0 && y+dy[i] < n && visited[x+dx[i]][y+dy[i]] == 0 && perc[x+dx[i]][y+dy[i]] == 0){
            visited[x+dx[i]][y+dy[i]] = 1;
            dfs(x+dx[i],y+dy[i]);
        }
    }
}

int main(void){
    cin>>m>>n;
    perc.assign(m,vector<int>(n,0));
    visited.assign(m,vector<bool>(n,0));
    for(int i = 0;i < m;i++){
        for(int j = 0;j < n;j++){
            scanf("%1d",&perc[i][j]);
        }
    }
    for(int i = 0;i < n;i++){
        if(perc[0][i] == 0 && visited[0][i] == 0){
            visited[0][i] = 1;
            dfs(0,i);
        }
    }
    for(int i = 0;i < n;i++){
        if(visited[m-1][i] == 1){
            cout<<"YES";
            noelec = false;
            break;
        }
    }
    if(noelec == true){
        cout<<"NO";
    }
    return 0;
}