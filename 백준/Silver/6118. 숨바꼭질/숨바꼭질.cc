#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(void){
    int n,m,a,b,check = 0,result,far = 0;
    cin>>n>>m;
    vector<int> has[n];
    vector<bool> visited(n,0);
    vector<int> barn(n,0);
    queue<pair<int,int>> togo;
    for(int i = 0;i < m;i++){
        cin>>a>>b;
        has[a-1].push_back(b-1);
        has[b-1].push_back(a-1);
    }
    togo.push({0,0});
    visited[0] = 1;
    while(!togo.empty()){
        int x = togo.front().first;
        int cost = togo.front().second;
        togo.pop();
        if(x != 0){
            barn[x] = cost;
        }
        for(int j = 0;j < has[x].size();j++){
            if(visited[has[x][j]] == 0){
                visited[has[x][j]] = 1;
                togo.push({has[x][j],cost+1});
            }
        }
    }
    for(int i = 1;i < n;i++){
        if(barn[i] > far){
            check = i+1;
            result = 1;
            far = barn[i]; 
        }
        else if(barn[i] == far){
            result++;
        }
    }
    cout<<check<<" "<<far<<" "<<result;
    return 0;
}