#include<iostream>
#include<vector>
#include<queue>
#include<tuple>

using namespace std;
int tomato[100][100][100];

int main(void){
    int M,N,H,days = 0;
    int tx[6] = {0,0,-1,1,0,0};
    int ty[6] = {1,-1,0,0,0,0};
    int tz[6] = {0,0,0,0,1,-1};
    cin>>M>>N>>H;

    queue<tuple<int,int,int>> togo;
    for(int i = 0;i < H;i++){
        for(int j = 0;j < N;j++){
            for(int k = 0;k < M;k++){
                scanf("%d",&tomato[i][j][k]);
            }
        }
    }
    for(int i = 0;i < H;i++){
        for(int j = 0;j < N;j++){
            for(int k = 0;k < M;k++){
                if(tomato[i][j][k] == 1){
                    togo.push(make_tuple(i,j,k));
                }
            }
        }
    }
    while(!togo.empty()){
        int x = get<1>(togo.front());
        int y = get<2>(togo.front());
        int z = get<0>(togo.front());
        togo.pop();
        for(int i = 0;i < 6;i++){
            if(x+tx[i] >= 0 && x+tx[i] < N && y+ty[i] >= 0 && y+ty[i] < M && z+tz[i] >= 0 && z+tz[i] < H && tomato[z+tz[i]][x+tx[i]][y+ty[i]] == 0){
                tomato[z+tz[i]][x+tx[i]][y+ty[i]] = tomato[z][x][y] + 1;
                togo.push({z+tz[i],x+tx[i],y+ty[i]});
            }
        }
    }
    for(int i = 0;i < H;i++){
        for(int j = 0;j < N;j++){
            for(int k = 0;k < M;k++){
            if (tomato[i][j][k] == 0){
                cout << -1 << endl;
                return 0;
            }
            if (days < tomato[i][j][k]){ 
                days = tomato[i][j][k];
            }
        }
    }
    }
    cout <<days-1;
    return 0;
}