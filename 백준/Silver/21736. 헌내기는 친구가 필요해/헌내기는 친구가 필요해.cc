#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<vector<int>> campus;

int main(void){
    int N,M,count = 0;
    int tx[4] = {0,0,-1,1};
    int ty[4] = {1,-1,0,0};
    char point;
    cin>>N>>M;
    campus.resize(N,vector<int>(M,0));
    queue<pair<int,int>> togo;
    for(int i = 0;i < N;i++){
        for(int j = 0;j < M;j++){
            cin>>point;
            if(point == 'O'){
                campus[i][j] = 0;
            }
            if(point == 'X'){
                campus[i][j] = -1;
            }
            if(point == 'I'){
                campus[i][j] = 1;
                togo.push({i,j});
            }
            if(point == 'P'){
                campus[i][j] = 2;
            }
        }
    }
    while(!togo.empty()){
        int x = togo.front().first;
        int y = togo.front().second;
        togo.pop();
        for(int i = 0;i < 4;i++){
            if(x+tx[i] >= 0 && x+tx[i] < N && y+ty[i] >= 0 && y+ty[i] < M){
                if(campus[x+tx[i]][y+ty[i]] == 0){
                    campus[x+tx[i]][y+ty[i]] = 1;
                    togo.push({x+tx[i],y+ty[i]});
                }
                if(campus[x+tx[i]][y+ty[i]] == 2){
                    campus[x+tx[i]][y+ty[i]] = 1;
                    count++;
                    togo.push({x+tx[i],y+ty[i]});
                }
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