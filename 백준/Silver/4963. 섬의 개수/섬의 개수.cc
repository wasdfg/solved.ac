#include<iostream>
#include<vector>

using namespace std;

vector<vector<bool>> island;
vector<vector<bool>> visited;
int dy[8] = {0,0,-1,1,-1,1,-1,1};
int dx[8] = {1,-1,0,0,-1,1,1,-1};
int w,h,count;

void dfs(int x,int y){
    for(int i = 0;i < 8;i++){
        if(x+dx[i] >= 0 && x+dx[i] < h && y+dy[i] >= 0 && y+dy[i] < w && island[x+dx[i]][y+dy[i]] == 1 && visited[x+dx[i]][y+dy[i]] == 0){
            visited[x+dx[i]][y+dy[i]] = 1;
            dfs(x+dx[i],y+dy[i]);
        }
    }
}

int main(void){
    while(1){
        cin>>w>>h;
        if(w == 0 && h == 0){
            break;
        }
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
                    dfs(i,j);
                }
            }
        }
    cout<<count<<"\n";
    }
    return 0;
}