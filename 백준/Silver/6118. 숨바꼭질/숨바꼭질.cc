#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(void){
    int n,m,a,b,check = 0,far = 50001,count = 0;
    cin>>n>>m;
    far = n-1;
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
        int now = togo.front().first;
        int cost = togo.front().second;
        togo.pop();
        for(int i = 0;i < has[now].size();i++){
            if(visited[has[now][i]] == 0){
                barn[has[now][i]] = cost+1;
                visited[has[now][i]] = 1;
                if(barn[has[now][i]] > check){
                    check = barn[has[now][i]];
                }
                togo.push({has[now][i],cost+1});
            }
        }
    }
    for(int i = 0;i < barn.size();i++){
        if(barn[i] == check){
            far = min(far,i+1);
            count++;
        }
    }
    cout<<far<<" "<<barn[far-1]<<" "<<count;
    return 0;
}