#include<iostream>
#include<vector>
#include<stack>
#include<queue>

using namespace std;

vector<int> dist;
vector<int> path;
vector<pair<int,int>> city[1000];

int main(void){
    int n,m,a,b,c,st,ed;
    cin>>n>>m;
    for(int i = 0;i < m;i++){
        cin>>a>>b>>c;
        city[a-1].push_back({b-1,c});
    }
    cin>>st>>ed;
    dist.assign(n,1000000001);
    path.assign(n,0);
    dist[st-1] = 0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> togo;
    togo.push({0,st-1});
    while(!togo.empty()){
        int cost = togo.top().first;
        int now = togo.top().second;
        togo.pop();
        if(dist[now] < cost){
            continue;
        }
        for(int i = 0;i < city[now].size();i++){
            int next = city[now][i].first;
            int ncost = city[now][i].second;
            if(cost+ncost >= dist[next]){
                continue;
            }
                dist[next] = cost+ncost;
                togo.push({cost+ncost,next});
                path[next] = now;
        }
    }
    cout<<dist[ed-1]<<endl;
    stack<int> route;
    int cur = ed-1;
    while(1){
        if(cur == st-1){
            route.push(st-1);
            break;
        }
        route.push(cur);
        cur = path[cur];
    }
    cout<<route.size()<<endl;
    while(!route.empty()){
        cout<<route.top()+1<<" ";
        route.pop();
    }
    return 0;
}