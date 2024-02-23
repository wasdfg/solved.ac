#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<vector<int>> board;
vector<vector<bool>> visited;
int pic,n,m;
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

int dfs(int x,int y){
    pic++;
    visited[x][y] = 1;
    for(int i = 0;i < 4;i++){
        if(x+dx[i] >= 0 && x+dx[i] < n && y+dy[i] >= 0 && y+dy[i] < m && visited[x+dx[i]][y+dy[i]] == 0 && board[x+dx[i]][y+dy[i]] == 1){
            dfs(x+dx[i],y+dy[i]);
        }
    }
    return 0;
}

int main(void){
    cin>>n>>m;
    priority_queue<int> group;
    board.assign(n,vector<int>(m,0));
    visited.assign(n,vector<bool>(m,0));
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            cin>>board[i][j];
        }
    }
    
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            if(board[i][j] == 1 && visited[i][j] == 0){
                pic = 0;
                dfs(i,j);
                group.push(pic);
            }
        }
    }
    cout<<group.size()<<endl;
    if(group.empty()){
        cout<<"0";
    }
    else{
        cout<<group.top();
    }
    return 0;
}