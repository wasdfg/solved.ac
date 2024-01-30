#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(void){
    int V,E,a,b,c,min = 987654321;
    vector<pair<int,int>> graph[401];
    cin>>V>>E;
    vector<int> dist;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<bool> visited;
    for(int i = 0;i < E;i++){
        cin>>a>>b>>c;
        graph[a].push_back({b,c});    
    }
    for(int i = 1;i <= V;i++){
        pq.push({0,i});
        dist.assign(V+1,987654321);
        visited.assign(V+1,0);
        while(!pq.empty()){
            int cost = pq.top().first;
            int cur = pq.top().second;
            pq.pop();
            if(visited[cur] == true){
                continue;
            }
            if(cur == i && visited[cur] == true){
                break;
            }
            visited[cur] = true;
            for(int j = 0;j < graph[cur].size();j++){
                int ncost = graph[cur][j].second;
                int next = graph[cur][j].first;
                if(cost+ncost < dist[next]){
                    dist[next] = cost+ncost;
                    pq.push({dist[next],next});
                }
            }
        }
        if(min > dist[i]){
            min = dist[i];
        }
    }
    if(min == 987654321){
        cout<<"-1\n";
    }
    else{
        cout<<min<<"\n";
    }
    return 0;
}