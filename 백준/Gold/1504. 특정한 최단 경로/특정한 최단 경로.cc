#include<iostream>
#include<vector>
#include<queue>

using namespace std;

long long N,E;
vector<pair<long,long>> graph[801];

long long daijkstra(long long start,long long end){
    priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>> togo;
    togo.push({0,start});
    vector<long long> dist(N+1,987654321);
    //dist[start] = 0;
    while(!togo.empty()){
        long long cost = togo.top().first;
        long long now = togo.top().second;
        togo.pop();
        if(dist[now] < cost)
            continue;
        dist[now] = cost;
        for(long long i = 0;i < graph[now].size();i++){
            long long next = graph[now][i].first;
            long long ncost = graph[now][i].second;
            if(cost+ncost < dist[next]){
                dist[next] = cost+ncost;
                togo.push({cost+ncost,next});
            }
        }
    }
    return dist[end];
}

int main(void){
    long long a,b,c,v1,v2;
    cin>>N>>E;
    for(int i = 0;i < E;i++){
        cin>>a>>b>>c;
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }
    cin>>v1>>v2;
    long long t1 = daijkstra(1,v1)+daijkstra(v1,v2)+daijkstra(v2,N);
    long long t2 = daijkstra(1,v2)+daijkstra(v2,v1)+daijkstra(v1,N);
    if(t1 >= 987654321 && t2 >= 987654321){
        cout<<"-1";
    }
    else{
        cout<<min(t1,t2);
    }
    return 0;
}