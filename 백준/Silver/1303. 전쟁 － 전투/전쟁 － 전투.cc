#include<iostream>
#include<vector>

using namespace std;
int N,M,white = 0,black = 0,check;
bool notw = 0;
vector<vector<int>> war;
vector<vector<bool>> visited;
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};

int dfs(int x,int y){
    visited[x][y] = 1;
    check++;
    for(int i = 0;i < 4;i++){
        if(x+dx[i] >= 0 && x+dx[i] < M && y+dy[i] >= 0 && y+dy[i] < N && visited[x+dx[i]][y+dy[i]] == 0){
            if(notw == true && war[x+dx[i]][y+dy[i]] == 1){
                dfs(x+dx[i],y+dy[i]);
            }
            else if(notw == false && war[x+dx[i]][y+dy[i]] == 0){
                dfs(x+dx[i],y+dy[i]);
            }
        }
    }
    return 0;
}

int main(void){
    char a;
    cin>>N>>M;
    war.assign(M,vector<int>(N,0));
    visited.assign(M,vector<bool>(N,0));
    for(int i = 0;i < M;i++){
        for(int j = 0;j < N;j++){
            cin>>a;
            if(a == 'W'){
                war[i][j] = 0;
            }
            else{
                war[i][j] = 1;
            }
        }
    }
    for(int i = 0;i < M;i++){
        for(int j = 0;j < N;j++){
            if(visited[i][j] == 0){
                check = 0;
                if(war[i][j] == 1){
                    notw = 1;
                }
                dfs(i,j);
                if(notw == 1){
                    black+=(check*check);
                }
                else{
                    white+=(check*check);
                }
                notw = 0;
            }
        }
    }
    cout<<white<<" "<<black;
    return 0;
}