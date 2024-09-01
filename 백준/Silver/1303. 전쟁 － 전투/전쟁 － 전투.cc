#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(void){
    int dx[4] = {0,0,-1,1};
    int dy[4] = {1,-1,0,0};
    int n,m,white = 0,blue = 0,check;
    bool notw = 0;
    char a;
    cin>>n>>m;
    vector<vector<int>> war(m,vector<int>(n,0));
    vector<vector<bool>> visited(m,vector<bool>(n,0));
    for(int i = 0;i < m;i++){
        for(int j = 0;j < n;j++){
            cin>>a;
            if(a == 'W'){
                war[i][j] = 0; 
            }
            else{
                war[i][j] = 1;
            }
        }
    }
    for(int i = 0;i < m;i++){
        for(int j = 0;j < n;j++){
            if(visited[i][j] == 0){
                check = 1;
                visited[i][j] = 1;
                if(war[i][j] == 1){
                    notw = 1;
                }
                else{
                    notw = 0;
                }
                queue<pair<int,int>> togo;
                togo.push({i,j});
                while(!togo.empty()){
                    int x = togo.front().first;
                    int y = togo.front().second;
                    togo.pop();               
                    for(int k = 0;k < 4;k++){
                        if(x+dx[k] >= 0 && x+dx[k] < m && y+dy[k] >= 0 && y+dy[k] < n && war[x+dx[k]][y+dy[k]] == notw && visited[x+dx[k]][y+dy[k]] == 0){
                            visited[x+dx[k]][y+dy[k]] = 1;
                            check++;
                            togo.push({x+dx[k],y+dy[k]});
                        }
                    }
                }
                if(notw == 0){
                    white+=(check*check);
                }
                else{
                    blue+=(check*check);
                } 
            }
        }
    }
    cout<<white<<" "<<blue;
    return 0;
}