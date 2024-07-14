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
    vector<vector<int>> color(n,vector<int>(n,0));
    vector<vector<bool>> visited(n,vector<bool>(n,0));
    queue<pair<int,int>> togo;

    for(int i = 0;i < n;i++){
        cin>>s;
        for(int j = 0;j < s.length();j++){
            if(s[j] == 'R'){
                color[i][j] = 1;
            }
            else if(s[j] == 'B'){
                color[i][j] = 2;
            }
            else{
                color[i][j] = 3;
            }
        }
    }
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            if(visited[i][j] == 0){
                visited[i][j] = 1;
                togo.push({i,j});
                if(color[i][j] == 1){
                    check = 1;
                }
                else if(color[i][j] == 2){
                    check = 2;
                }
                else{
                    check = 3;
                }
                while(!togo.empty()){
                    int x = togo.front().first;
                    int y = togo.front().second;
                    togo.pop();
                    for(int k = 0;k < 4;k++){
                        if(x+dx[k] >= 0 && x+dx[k] < n && y+dy[k] >= 0 && y+dy[k] < n && visited[x+dx[k]][y+dy[k]] == 0 && color[x+dx[k]][y+dy[k]] == check){
                            visited[x+dx[k]][y+dy[k]] = 1;
                            togo.push({x+dx[k],y+dy[k]});
                        }
                    }
                }
                noblind++;

            }
        }
    }
    visited.assign(n,vector<bool>(n,0));
    while(!togo.empty()){
        togo.pop();
    }
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            if(visited[i][j] == 0){
                visited[i][j] = 1;
                togo.push({i,j});
                if(color[i][j] == 1 || color[i][j] == 3){
                    check = 1;
                }
                else{
                    check = 0;
                }
                while(!togo.empty()){
                    int x = togo.front().first;
                    int y = togo.front().second;
                    togo.pop();
                    for(int k = 0;k < 4;k++){
                        if(x+dx[k] >= 0 && x+dx[k] < n && y+dy[k] >= 0 && y+dy[k] < n && visited[x+dx[k]][y+dy[k]] == 0 && color[x+dx[k]][y+dy[k]]% 2 == check){
                            visited[x+dx[k]][y+dy[k]] = 1;
                            togo.push({x+dx[k],y+dy[k]});
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