#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(void){
    int n,height = 0,area = 0,maxarea = 1;
    cin>>n;
    vector<vector<int>> rain(n,vector<int>(n,0));
    vector<vector<bool>> visited(n,vector<bool>(n,0));
    queue<pair<int,int>> togo;
    int dx[4] = {0,0,-1,1};
    int dy[4] = {1,-1,0,0};
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            cin>>rain[i][j];
            if(height < rain[i][j]){
                height = rain[i][j];
            }
        }
    }
    for(int k = 1;k <= height;k++){
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                if(rain[i][j] > k && visited[i][j] == 0){
                    togo.push({i,j});
                    visited[i][j] = 1;
                    while(!togo.empty()){
                        int x = togo.front().first;
                        int y = togo.front().second;
                        togo.pop();
                        for(int l = 0;l < 4;l++){
                            if(x+dx[l] >= 0 && x+dx[l] < n && y+dy[l] >= 0 && y+dy[l] < n){
                                if(rain[x+dx[l]][y+dy[l]] > k && visited[x+dx[l]][y+dy[l]] == 0){
                                    visited[x+dx[l]][y+dy[l]] = 1;
                                    togo.push({x+dx[l],y+dy[l]});
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
        visited.assign(n,vector<bool>(n,0));
    }
    cout<<maxarea;
    return 0;
}