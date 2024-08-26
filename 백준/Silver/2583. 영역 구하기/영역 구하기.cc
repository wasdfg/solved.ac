#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(void){
    int n,m,check,k,x1,y1,x2,y2;
    int dx[4] = {0,0,-1,1};
    int dy[4] = {1,-1,0,0};
    cin>>n>>m>>k;
    vector<vector<int>> monun(n,vector<int>(m,1));
    vector<vector<bool>> visited(n,vector<bool>(m,0));
    priority_queue<int,vector<int>,greater<int>> result;
    queue<pair<int,int>> togo;
    for(int i = 0;i < k;i++){
        cin>>x1>>y1>>x2>>y2;
        for(int a = y1;a < y2;a++){
            for(int b = x1;b < x2;b++){
                monun[a][b] = 0;
            } 
        }
    }
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            if(monun[i][j] == 1 && visited[i][j] == 0){
                int area = 1;
                visited[i][j] = 1;
                togo.push({i,j});
                while(!togo.empty()){
                    int x = togo.front().first;
                    int y = togo.front().second;
                    togo.pop();
                    for(int a = 0;a < 4;a++){
                        if(x+dx[a] >= 0 && x+dx[a] < n && y+dy[a] >= 0 && y+dy[a] < m && monun[x+dx[a]][y+dy[a]] == 1 && visited[x+dx[a]][y+dy[a]] == 0){
                            area++;
                            visited[x+dx[a]][y+dy[a]] = 1;
                            togo.push({x+dx[a],y+dy[a]});
                        }
                    }
                }
                result.push(area);
            }
        }
    }
    cout<<result.size()<<"\n";
    while(!result.empty()){
        cout<<result.top()<<" ";
        result.pop();
    }
    return 0;
}