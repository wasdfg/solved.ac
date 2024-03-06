#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(void){
    int m,n;
    bool noelec = true;
    int dx[4] = {0,0,-1,1};
    int dy[4] = {1,-1,0,0};
    cin>>m>>n;
    vector<vector<int>> perc(m,vector<int>(n,0));
    vector<vector<bool>> visited(m,vector<bool>(n,0));
    priority_queue<pair<int,int>> togo;
    for(int i = 0;i < m;i++){
        for(int j = 0;j < n;j++){
            scanf("%1d",&perc[i][j]);
        }
    }
    for(int i = 0;i < n;i++){
        if(perc[0][i] == 0 && visited[0][i] == 0){
            visited[0][i] = 1;
            togo.push({0,i});
            while(!togo.empty()){
                int x = togo.top().first;
                int y = togo.top().second;
                togo.pop();
                for(int j = 0;j < 4;j++){
                    if(x+dx[j] >= 0 && x+dx[j] < m && y+dy[j] >= 0 && y+dy[j] < n){
                        if(perc[x+dx[j]][y+dy[j]] == 0 && visited[x+dx[j]][y+dy[j]] == 0){
                            visited[x+dx[j]][y+dy[j]] = 1;
                            togo.push({x+dx[j],y+dy[j]});
                        }
                    }
                }
            }
        }
    }
    for(int i = 0;i < n;i++){
        if(visited[m-1][i] == 1){
            cout<<"YES";
            noelec = false;
            break;
        }
    }
    if(noelec == true){
        cout<<"NO";
    }
    return 0;
}