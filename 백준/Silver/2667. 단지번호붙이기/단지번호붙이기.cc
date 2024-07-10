#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int main(void){
    int n,count = 0;
    cin>>n;
    vector<int> result;
    vector<vector<bool>> area(n,vector<bool>(n,0));
    vector<vector<bool>> visited(n,vector<bool>(n,0));
    int dx[4] = {0,0,-1,1};
    int dy[4] = {1,-1,0,0};
    queue<pair<int,int>> togo;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            int t;
            scanf("%1d",&t);
            area[i][j] = t;
        }
    }
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            if(area[i][j] == 1 && visited[i][j] == 0){
                visited[i][j] = 1;
                togo.push({i,j});
                count = 1;
                while(!togo.empty()){
                    int x = togo.front().first;
                    int y = togo.front().second;
                    togo.pop();
                    for(int k = 0;k < 4;k++){
                        if(x+dx[k] >= 0 && x+dx[k] < n && y+dy[k] >= 0 && y+dy[k] < n && visited[x+dx[k]][y+dy[k]] == 0 && area[x+dx[k]][y+dy[k]] == 1){
                            visited[x+dx[k]][y+dy[k]] = 1;
                            count++;
                            togo.push({x+dx[k],y+dy[k]});
                        }
                    }
                }
                result.push_back(count);
            }
        }
    }
    sort(result.begin(),result.end());
    cout<<result.size()<<endl;
    for(auto a:result){
        cout<<a<<endl;
    }
    return 0;
}