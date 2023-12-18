#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(void){
    int M,N,days = 0;
    int tx[4] = {0,0,-1,1};
    int ty[4] = {1,-1,0,0};
    cin>>M>>N;
    vector<vector<int>> tomato(1000,vector<int>(1000,0));
    queue<pair<int,int>> togo;
    for(int i = 0;i < N;i++){
        for(int j = 0;j < M;j++){
            cin>>tomato[i][j];
        }
    }
    for(int i = 0;i < N;i++){
        for(int j = 0;j < M;j++){
            if(tomato[i][j] == 1){
                togo.push({i,j});
            }
        }
    }
    while(!togo.empty()){
        int x = togo.front().first;
        int y = togo.front().second;
        togo.pop();
        for(int i = 0;i < 4;i++){
            if(x+tx[i] >= 0 && x+tx[i] < N && y+ty[i] >= 0 && y+ty[i] < M && tomato[x+tx[i]][y+ty[i]] == 0){
                tomato[x+tx[i]][y+ty[i]] = tomato[x][y] + 1;
                togo.push({x+tx[i],y+ty[i]});
            }
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (tomato[i][j] == 0) {
                cout << -1 << endl;
                return 0;
            }
            if (days < tomato[i][j]){ 
                days = tomato[i][j];
            }
        }
    }
    cout <<days-1;
    return 0;
}