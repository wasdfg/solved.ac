#include<iostream>
#include<vector>
#include<queue>

using namespace std;
vector<vector<bool>> island;
vector<vector<bool>> visited;
queue<pair<int,int>> togo;
int ty[8] = {0,0,-1,1,-1,1,-1,1};
int tx[8] = {1,-1,0,0,-1,1,1,-1};

int main(void){
    int w,h,count;
    while(1){
        cin>>w>>h;
        if(w == 0 && h == 0){
            break;
        }
        island.resize(h,vector<bool>(w,0));
        visited.resize(h,vector<bool>(w,0));
        island.assign(h,vector<bool>(w,0));
        visited.assign(h,vector<bool>(w,0));
        int t;
        for(int i = 0;i < h;i++){
            for(int j = 0;j < w;j++){
                cin>>t;
                island[i][j] = t;
            }
        }
        count = 0;
        for(int i = 0;i < h;i++){
            for(int j = 0;j < w;j++){
                if(island[i][j] == 1 && visited[i][j] == 0){
                    count++;
                    togo.push({i,j});
                    visited[i][j] = 1;
                    while(!togo.empty()){
                        int x = togo.front().first;
                        int y = togo.front().second;
                        togo.pop();
                        for(int i = 0; i < 8;i++){
                            if(x+tx[i] >= 0 && x+tx[i] < h && y+ty[i] >= 0 && y+ty[i] < w){
                                if(island[x+tx[i]][y+ty[i]] == 1 && visited[x+tx[i]][y+ty[i]] == 0){
                                    visited[x+tx[i]][y+ty[i]] = 1;
                                    togo.push({x+tx[i],y+ty[i]});
                                }
                            }
                        }
                    }
                }
            }
        }
    cout<<count<<"\n";
    }
    return 0;
}