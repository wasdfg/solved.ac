#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> yard;
vector<vector<bool>> visited;
int R,C,sheep,wolf;
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};

int dfs(int x,int y){
    visited[x][y] = 1;
    if(yard[x][y] == 2){
        sheep++;
    }
    if(yard[x][y] == 3){
        wolf++;
    }
    for(int i = 0;i < 4;i++){
        if(x+dx[i] >= 0 && x+dx[i] < R && y+dy[i] >= 0 && y+dy[i] < C && visited[x+dx[i]][y+dy[i]] == 0 && yard[x+dx[i]][y+dy[i]] != 1){
            dfs(x+dx[i],y+dy[i]);
        }
    }
    return 0;
}

int main(void){
    int lives = 0,livew = 0;
    char a;
    cin>>R>>C;
    yard.assign(R,vector<int>(C,0));
    visited.assign(R,vector<bool>(C,0));
    for(int i = 0;i < R;i++){
        for(int j = 0;j < C;j++){
            cin>>a;
            if(a == '.'){
                yard[i][j] = 0;
            }
            else if(a == '#'){
                yard[i][j] = 1;
            }
            else if(a == 'o'){
                yard[i][j] = 2;
            }
            else if(a == 'v'){
                yard[i][j] = 3;
            }
        }
    }
    for(int i = 0;i < R;i++){
        for(int j = 0;j < C;j++){
            sheep = 0;
            wolf = 0;
            if(yard[i][j] != 1 && visited[i][j] == 0){
                dfs(i,j);
                if(sheep > wolf && !(wolf == 0 && sheep == 0)){
                    lives+= sheep;
                }
                else if(sheep <= wolf && !(wolf == 0 && sheep == 0)){
                    livew+= wolf;
                }
            }
        }
    }
    cout<<lives<<" "<<livew;
    return 0;
}