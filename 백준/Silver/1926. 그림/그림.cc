#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(void){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> paint(n,vector<int>(m,0));
    vector<vector<bool>> visited(n,vector<bool>(m,0));
    int dx[4] = {0,0,-1,1};
    int dy[4] = {1,-1,0,0};
    priority_queue<int> area;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            cin>>paint[i][j];
        }
    }
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            int check = 0;
            if(paint[i][j] == 1 && visited[i][j] == 0){
                visited[i][j] = 1;
                check = 1;
                queue<pair<int,int>> togo;
                togo.push({i,j});
                while(!togo.empty()){
                    int x = togo.front().first;
                    int y = togo.front().second;
                    togo.pop();
                    for(int k = 0;k < 4;k++){
                        if(x+dx[k] >= 0 && x+dx[k] < n && y+dy[k] >= 0 && y+dy[k] < m && paint[x+dx[k]][y+dy[k]] == 1 && visited[x+dx[k]][y+dy[k]] == 0){
                            visited[x+dx[k]][y+dy[k]] = 1;
                            check++;
                            togo.push({x+dx[k],y+dy[k]});
                        }
                    }
                }
                area.push(check);
            }
        }
    }
    if(area.empty()){
        cout<<"0\n0";
    }
    else{
        cout<<area.size()<<"\n"<<area.top();
    }
    return 0;
}