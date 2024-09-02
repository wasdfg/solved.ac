#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int n,m,k,r,c,count,result = 0;
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
vector<vector<int>> trash;
vector<vector<bool>> visited;

void dfs(int x,int y){
    for(int i = 0;i < 4;i++){
        if(x+dx[i] >= 0 && x+dx[i] < n && y+dy[i] >= 0 && y+dy[i] < m && trash[x+dx[i]][y+dy[i]] == 1 && visited[x+dx[i]][y+dy[i]] == 0){
            visited[x+dx[i]][y+dy[i]] = 1;
            count++;
            dfs(x+dx[i],y+dy[i]);
        }
    }
}

int main(void){
    cin>>n>>m>>k;
    trash.assign(n,vector<int>(m,0));
    visited.assign(n,vector<bool>(m,0));
    for(int i = 0;i < k;i++){
        cin>>r>>c;
        trash[r-1][c-1] = 1;
    }
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            if(trash[i][j] == 1 && visited[i][j] == 0){
                count = 1;
                visited[i][j] = 1;
                dfs(i,j);
                result = max(count,result);
            }
        }
    }
    cout<<result;
    return 0;
}