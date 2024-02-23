#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<vector<bool>> monun;
vector<vector<bool>> visited;
int n,m,check;
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};

int dfs(int x,int y){
    check++;
    visited[x][y] = 1;
    for(int i = 0;i < 4;i++){
        if(x+dx[i] >= 0 && x+dx[i] < m && y+dy[i] >= 0 && y+dy[i] < n && monun[x+dx[i]][y+dy[i]] == 0 && visited[x+dx[i]][y+dy[i]] == 0){
            dfs(x+dx[i],y+dy[i]);
        }
    }
    return 0;
}

int main(void){
    int k,x1,y1,x2,y2;
    priority_queue<int,vector<int>,greater<int>> area;
    cin>>m>>n>>k;
    monun.assign(m,vector<bool>(n,0));
    visited.assign(m,vector<bool>(n,0));
    for(int i = 0;i < k;i++){
        cin>>x1>>y1>>x2>>y2;
        for(int a = y1;a < y2;a++){
            for(int b = x1;b < x2;b++){
                monun[a][b] = 1;
            }
        }
    }
    for(int i = 0;i < m;i++){
        for(int j = 0;j < n;j++){
            if(monun[i][j] == 0 && visited[i][j] == 0){
                check = 0;
                dfs(i,j);
                area.push(check);
            }
        }
    }
    cout<<area.size()<<endl;
    while(!area.empty()){
        cout<<area.top()<<" ";
        area.pop();
    }
    return 0;
}