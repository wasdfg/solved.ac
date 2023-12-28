#include<iostream>
#include<vector>
#include<queue>

using namespace std;
vector<vector<int>> rain;
vector<vector<bool>> visited;

int main(void){
    int N,maxv = 0,area = 0,maxarea = 0;
    cin>>N;
    rain.resize(N,vector<int>(N,0));
    visited.resize(N,vector<bool>(N,0));
    queue<pair<int,int>> togo;
    int tx[4] = {0,0,-1,1};
    int ty[4] = {1,-1,0,0};
    for(int i = 0;i < N;i++){
        for(int j = 0;j < N;j++){
            cin>>rain[i][j];
            if(maxv < rain[i][j]){
                maxv = rain[i][j];
            }
        }
    }
    for(int i = 0;i <= maxv;i++){
        for(int j = 0;j < N;j++){
            for(int k = 0;k < N;k++){
                if(rain[j][k] > i && visited[j][k] == false){
                    togo.push({j,k});
                    visited[j][k] == true;
                    while(!togo.empty()){
                        int x = togo.front().first;
                        int y = togo.front().second;
                        togo.pop();
                        for(int l = 0;l < 4;l++){
                            if(x+tx[l] >= 0 && x+tx[l] < N && y+ty[l] >= 0 && y+ty[l] < N){
                                if(rain[x+tx[l]][y+ty[l]] > i && visited[x+tx[l]][y+ty[l]] == false){
                                    visited[x+tx[l]][y+ty[l]] = true;
                                    togo.push({x+tx[l],y+ty[l]});
                                }
                            }
                        }
                    }
                    area++;
                }
            }
        }
        if(area > maxarea){
            maxarea = area;
        }
        area = 0;
        visited.assign(N,vector<bool>(N,false));
    }
    cout<<maxarea;
    return 0;
}