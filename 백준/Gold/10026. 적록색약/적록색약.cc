#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> RGB;
vector<vector<bool>> visited;
int remember,N;
int tx[4] = {0,0,-1,1};
int ty[4] = {1,-1,0,0};

int DFS(int x,int y){
    for(int i = 0;i < 4;i++){
        if(x+tx[i] < 0 || x+tx[i] >= N || y+ty[i] < 0 || y+ty[i] >= N){
            continue;
        }
        if(visited[x+tx[i]][y+ty[i]] == 0 && RGB[x+tx[i]][y+ty[i]] == remember){
            visited[x+tx[i]][y+ty[i]] = 1;
            DFS(x+tx[i],y+ty[i]);
        }
    }
    return 0;
}

int main(void){
    int normal = 0,blind = 0;
    char color;
    cin>>N;
    RGB.resize(N,vector<int>(N,0));
    visited.resize(N,vector<bool>(N,0));
    for(int i = 0;i < N;i++){
        for(int j = 0;j < N;j++){
            cin>>color;
            if(color == 'R'){
                RGB[i][j] = 1;
            }
            else if(color == 'G'){
                RGB[i][j] = 2;
            }
            else{
                RGB[i][j] = 3;
            }
        }
    }
    for(int i = 0;i < N;i++){
        for(int j = 0;j < N;j++){
            if(visited[i][j] == 0){
                remember = RGB[i][j];
                visited[i][j] = 1;
                DFS(i,j);
                normal++;
            }
        }
    }

    for(int i = 0;i < N;i++){
        for(int j = 0;j < N;j++){
            if(RGB[i][j] == 2){
                RGB[i][j] = 1;
            }
        }
    }
    visited.assign(N,vector<bool>(N,0));
    for(int i = 0;i < N;i++){
        for(int j = 0;j < N;j++){
            if(visited[i][j] == 0){
                remember = RGB[i][j];
                visited[i][j] = 1;
                DFS(i,j);
                blind++;
            }
        }
    }
    cout<<normal<<" "<<blind<<endl;
}