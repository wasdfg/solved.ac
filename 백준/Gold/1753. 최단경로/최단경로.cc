#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int v,e,k,a,b,c;
    cin>>v>>e>>k;
    vector<pair<int,int>> graph[v+1];
    vector<int> take(v+1,2000000000);
    priority_queue<pair<int,int>> togo;
    for(int i = 0;i < e;i++){
        cin>>a>>b>>c;
        graph[a].push_back({b,c});
    }
    take[k] = 0;
    togo.push({0,k});
    while(!togo.empty()){
        int now = togo.top().second;
        int cost = -togo.top().first;
        togo.pop();
        if(cost > take[now]){
            continue;
        }
        for(int i = 0;i < graph[now].size();i++){
            int next = graph[now][i].first;
            int ncost = cost+graph[now][i].second;
            if(ncost < take[next]){
                take[next] = ncost;
                togo.push({-ncost,next});
            }
        }
    }
    for(int i = 1;i < v+1;i++){
        if(take[i] == 2000000000){
            cout<<"INF\n";
        }
        else{
            cout<<take[i]<<"\n";
        }
    }
    return 0;
}