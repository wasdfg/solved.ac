#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int main(void){
    long long n,m,a,b,c,s,e;
    bool check = 0;
    cin>>n>>m;
    vector<pair<long long,long long>> daijk[n];
    vector<long long> weight(n,-1);
    for(int i = 0;i < m;i++){
        cin>>a>>b>>c;
        daijk[a-1].push_back({b-1,c});
        daijk[b-1].push_back({a-1,c});
    }
    for(int i = 0;i < n;i++){
        sort(daijk[i].begin(),daijk[i].end());
    }
    cin>>s>>e;
    priority_queue<pair<long long,long long>> togo;
    weight[s-1] = 1e+15;
    togo.push({1e+15,s-1});
    while(!togo.empty()){
        long long cost = togo.top().first;
        long long now = togo.top().second;
        togo.pop();
        if(weight[now] > cost){
            continue;
        }
        for(int i = 0;i < daijk[now].size();i++){
            long long next = daijk[now][i].first;
            long long ncost = min(cost,daijk[now][i].second);
            if(ncost > weight[next]){
                weight[next] = ncost;
                togo.push({ncost,next});
            }
        }
    }
    cout<<weight[e-1];
    return 0;
}