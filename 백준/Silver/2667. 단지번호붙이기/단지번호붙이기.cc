#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

int main(void){
    int dx[4] = {0,0,-1,1};
    int dy[4] = {1,-1,0,0};
    int n,area;
    cin>>n;
    vector<vector<int>> graph(n,vector<int>(n,0));
    vector<int> areas;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            scanf("%1d",&graph[i][j]);
        }
    }
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            if(graph[i][j] == 1){
                graph[i][j] = 0;
                queue<pair<int,int>> togo;
                togo.push({i,j});
                area = 1;
                while(!togo.empty()){
                    int x = togo.front().first;
                    int y = togo.front().second;
                    togo.pop();
                    for(int a = 0;a < 4;a++){
                        if(x+dx[a] >= 0 && x+dx[a] < n && y+dy[a] >= 0 && y+dy[a] < n && graph[x+dx[a]][y+dy[a]] == 1){
                            graph[x+dx[a]][y+dy[a]] = 0;
                            area++;
                            togo.push({x+dx[a],y+dy[a]});
                        }
                    }
                }
                areas.push_back(area);
            }
        }
    }
    sort(areas.begin(),areas.end());
    cout<<areas.size()<<"\n";
    for(int i = 0;i < areas.size();i++){
        cout<<areas[i]<<"\n";
    }
}