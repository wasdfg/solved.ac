#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    long long v,e,a,b,c,result = 0;
    cin>>v>>e;
    vector<pair<long long,long long>> prim[v+1];
    vector<bool> visited(v+1,0);
    priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> togo;
    for(int i = 0;i < e;i++){
        cin>>a>>b>>c;
        prim[a].push_back({b,c});
        prim[b].push_back({a,c});
    }
    togo.push({0,1});
    while(!togo.empty()){
        int x = togo.top().second;
        long long check = togo.top().first;
        togo.pop();
        if(visited[x] == 1){
            continue;
        }
        visited[x] = 1;
        result+=check;
        for(int i = 0;i < prim[x].size();i++){
            if(visited[prim[x][i].first] == 0){
                togo.push({prim[x][i].second,prim[x][i].first});
            }
        }
    }
    cout<<result;
    return 0;
}