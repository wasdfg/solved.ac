#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#define ull unsigned long long

using namespace std;
vector<pair<int,int>> route[1001];
vector<ull> len;
int start,last,N;

int daijkstra(int start){
    priority_queue<pair<ull,ull>> pq;
    pq.push({start,0});
    len[start] = 0;
    while(!pq.empty()){
        int cur = pq.top().first;
        int cost = -pq.top().second;
        pq.pop();
        if(cost > len[cur]){
            continue;
        }
        for(int i = 0;i < route[cur].size();i++){
            int next = route[cur][i].first;
            int ncost = route[cur][i].second;
            if(len[next] > cost+ncost){
                len[next] = cost+ncost;
                pq.push({next,-len[next]});
            }
        }
    }
    return 0;
}


int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int M,x,y,cost;
    cin>>N>>M;
    len.resize(N+1,999999999);

    for(int i = 0;i < M;i++){
        cin>>x>>y>>cost;
        route[x].push_back({y,cost});
    }

    cin>>start>>last;
    daijkstra(start);
    cout<<len[last];
    return 0;
}