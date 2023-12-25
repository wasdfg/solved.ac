#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<pair<int,int>> graph[20001];
vector<int> mincost;
int V,E,K;

int daijkstra(int start){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    bool visited[20001] = {0,};
    pq.push({0,start});
    mincost[start] = 0;
    while(!pq.empty()){
        int cost = pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        if(visited[cur] == true){
            continue;
        }
        visited[cur] = true;
        for(int i = 0;i < graph[cur].size();i++){
            int ncost = graph[cur][i].second;
            int next = graph[cur][i].first;
            if(mincost[next] > ncost + cost){
                mincost[next] = cost+ncost;
                pq.push({mincost[next],next});
            }
        }
    }
    return 0;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int u,v,e;
    cin>>V>>E;
    cin>>K;
    mincost.resize(V+1,99999999);
    for(int i = 0;i < E;i++){
        cin>>u>>v>>e;
        graph[u].push_back({v,e});
    }
    daijkstra(K);
    for(int i = 1;i <= V;i++){
        if(i == K){
            cout<<"0\n";
        }
        else{
            if(mincost[i] == 99999999){
                cout<<"INF\n";
            }
            else{
                cout<<mincost[i]<<endl;
            }
        }
    }
}