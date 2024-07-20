#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#define ull unsigned long long

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ull n,m,s,e,a,b,c;
    cin>>n>>m;
    vector<pair<ull,ull>> city[n+1];
    vector<ull> money(n+1,30000000000);
    priority_queue<pair<ull,ull>> togo;
    for(int i = 0;i < m;i++){
        cin>>a>>b>>c;
        city[a].push_back({b,c});
    }
    cin>>s>>e;
    money[s] = 0;
    togo.push({0,s});
    while(!togo.empty()){
        int now = togo.top().second;
        int cost = togo.top().first;
        togo.pop();
        if(cost > money[now]){
            continue;
        }
        for(int i = 0;i < city[now].size();i++){
            if(cost+city[now][i].second < money[city[now][i].first]){
                money[city[now][i].first] = cost+city[now][i].second;
                togo.push({cost+city[now][i].second,city[now][i].first});
            }
        }
    }
    cout<<money[e];
    return 0;
}