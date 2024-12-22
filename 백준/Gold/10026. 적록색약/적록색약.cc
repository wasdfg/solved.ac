#include<iostream>
#include<vector>
#include<string>
#include<queue>

using namespace std;

int main(void){
    int n,blind = 0,noblind = 0,check;
    int dx[4] = {0,0,-1,1};
    int dy[4] = {1,-1,0,0};
    string s;
    cin>>n;
    vector<string> color(n);
    vector<vector<bool>> visited(n,vector<bool>(n,0));
    queue<pair<int,int>> togo;
    for(int i = 0;i < n;i++){
        cin>>color[i];
    }
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            if(visited[i][j] == 0){
                togo.push({i,j});
                visited[i][j] = 1;
                char c = color[i][j];
                while(!togo.empty()){
                    int x = togo.front().first;
                    int y = togo.front().second;
                    togo.pop();
                    for(int i = 0;i < 4;i++){
                        if(x+dx[i] >= 0 && x+dx[i] < n && y+dy[i] >= 0 && y+dy[i] < n && color[x+dx[i]][y+dy[i]] == c && visited[x+dx[i]][y+dy[i]] == 0){
                            visited[x+dx[i]][y+dy[i]] = 1;
                            togo.push({x+dx[i],y+dy[i]});
                        }
                    }
                }
                noblind++;
            }
        }
    }
    visited.assign(n,vector<bool>(n,0));
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            if(color[i][j] == 'G'){
                color[i][j] = 'R';
            }
        }
    }
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            if(visited[i][j] == 0){
                togo.push({i,j});
                visited[i][j] = 1;
                char c = color[i][j];
                while(!togo.empty()){
                    int x = togo.front().first;
                    int y = togo.front().second;
                    togo.pop();
                    for(int i = 0;i < 4;i++){
                        if(x+dx[i] >= 0 && x+dx[i] < n && y+dy[i] >= 0 && y+dy[i] < n && color[x+dx[i]][y+dy[i]] == c && visited[x+dx[i]][y+dy[i]] == 0){
                            visited[x+dx[i]][y+dy[i]] = 1;
                            togo.push({x+dx[i],y+dy[i]});
                        }
                    }
                }
                blind++;
            }
        }
    }
    cout<<noblind<<" "<<blind;
    return 0;
}