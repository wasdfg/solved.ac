#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(void){
    int r,c,sheep,wolf;
    int dx[4] = {0,0,-1,1};
    int dy[4] = {1,-1,0,0};
    int livesheep = 0,livewolf = 0;
    char a;
    cin>>r>>c;
    vector<vector<int>> yard(r,vector<int>(c,0));
    vector<vector<bool>> visited(r,vector<bool>(c,0));
    for(int i = 0;i < r;i++){
        for(int j = 0;j < c;j++){
            cin>>a;
            if(a == '#'){
                yard[i][j] = 0;
            }
            else if(a == '.'){
                yard[i][j] = 1;
            }
            else if(a == 'o'){
                yard[i][j] = 2;
            }
            else if(a == 'v'){
                yard[i][j] = 3;
            }
        }
    }
    for(int i = 0;i < r;i++){
        for(int j = 0;j < c;j++){
            if(yard[i][j] >= 2 && visited[i][j] == 0){
                sheep = 0;
                wolf = 0;
                queue<pair<int,int>> togo;
                visited[i][j] = 1;
                togo.push({i,j});
                if(yard[i][j] == 2){
                    sheep++;
                }
                else{
                    wolf++;
                }
                while(!togo.empty()){
                    int x = togo.front().first;
                    int y = togo.front().second;
                    togo.pop();
                    for(int t = 0;t < 4;t++){
                        if(x+dx[t] >= 0 && x+dx[t] < r && y+dy[t] >= 0 && y+dy[t] < c && yard[x+dx[t]][y+dy[t]] > 0 && visited[x+dx[t]][y+dy[t]] == 0){
                            visited[x+dx[t]][y+dy[t]] = 1;
                            if(yard[x+dx[t]][y+dy[t]] == 2){
                                sheep++;
                            }
                            else if(yard[x+dx[t]][y+dy[t]] == 3){
                                wolf++;
                            }
                            togo.push({x+dx[t],y+dy[t]});
                        }
                    }
                }
                if(sheep > wolf && !(wolf == 0 && sheep == 0)){
                    livesheep+= sheep;
                }
                else if(sheep <= wolf && !(wolf == 0 && sheep == 0)){
                    livewolf+= wolf;
                }
            }
        }
    }
    cout<<livesheep<<" "<<livewolf;
    return 0;
}