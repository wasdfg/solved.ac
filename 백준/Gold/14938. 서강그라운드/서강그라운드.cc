#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(void){
    int n,m,r,a,b,c,result = 0;
    cin>>n>>m>>r;
    vector<pair<int,int>> zido[n+1];
    vector<int> stuff(n+1,0);
    
    for(int i = 1;i < n+1;i++){
        cin>>stuff[i];
    }
    for(int i = 0;i < r;i++){
        cin>>a>>b>>c;
        zido[a].push_back({b,c});
        zido[b].push_back({a,c});
    }
    for(int i = 1;i < n+1;i++){
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> togo;
        togo.push({0,i});
        vector<int> dist(n+1,1000000000);
        dist[i] = 0;
        while(!togo.empty()){
            int cost = togo.top().first;
            int now = togo.top().second;
            togo.pop();
            for(int j = 0;j < zido[now].size();j++){
                int ncost = zido[now][j].second;
                int next = zido[now][j].first;
                if(cost+ncost < dist[next]){
                    dist[next] = cost+ncost;
                    togo.push({dist[next],next});
                }
            }
        }
        int check = 0;
        for(int i = 1;i < n+1;i++){
            if(dist[i] <= m){
                check+=stuff[i];
            }
        }
        result = max(result,check);
    }
    cout<<result;
    return 0;
}