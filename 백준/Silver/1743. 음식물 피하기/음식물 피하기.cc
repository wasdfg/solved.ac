#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(void){
    int n,m,k,r,c,count,result = 0;
    int dx[4] = {0,0,-1,1};
    int dy[4] = {-1,1,0,0};
    cin>>n>>m>>k;
    vector<vector<int>> trash(n,vector<int>(m,0));
    vector<vector<bool>> visited(n,vector<bool>(m,0));
    for(int i = 0;i < k;i++){
        cin>>r>>c;
        trash[r-1][c-1] = 1;
    }
    priority_queue<pair<int,int>> togo;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            if(trash[i][j] == 1 && visited[i][j] == 0){
                count = 0;
                visited[i][j] = 1;
                togo.push({i,j});
                count++;
                while(!togo.empty()){
                    int x = togo.top().first;
                    int y = togo.top().second;
                    togo.pop();
                    for(int k = 0;k < 4;k++){
                        if(x+dx[k] >= 0 && x+dx[k] < n && y+dy[k] >= 0 && y+dy[k] < m && trash[x+dx[k]][y+dy[k]] == 1 && visited[x+dx[k]][y+dy[k]] == 0){
                            count++;
                            visited[x+dx[k]][y+dy[k]] = 1;
                            togo.push({x+dx[k],y+dy[k]});
                        }
                    }
                }
                if(count > result){
                    result = count;
                }
            }
        }
    }
    cout<<result;
    return 0;
}