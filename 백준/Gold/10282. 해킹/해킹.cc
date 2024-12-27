#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(void){
    int t,n,d,c,a,b,s,infect_count,infect_time;
    vector<pair<int,int>> computer[10001];
    cin>>t;
    for(int i = 0;i < t;i++){
        cin>>n>>d>>c;
        for(int i = 1;i < 10001;i++){
            computer[i].clear();
        }
        vector<int> taketime(n+1,100000000);
        for(int j = 0;j < d;j++){
            cin>>a>>b>>s;
            computer[b].push_back({a,s});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> togo;
        infect_count= 0;
        infect_time = 0;
        taketime[c] = 0;
        togo.push({0,c});
        while(!togo.empty()){
            int now = togo.top().second;
            int cost = togo.top().first;
            togo.pop();
            if(taketime[now] < cost){
                continue;
            }
            for(int j = 0;j < computer[now].size();j++){
                int next = computer[now][j].first;
                int ncost = computer[now][j].second;
                if(taketime[next] > cost+ncost){
                    taketime[next] = cost+ncost;
                    togo.push({cost+ncost,next});
                }
            }
        }
        for(int j = 1;j < n+1;j++){
            if(taketime[j] != 100000000){
                infect_count++;
                infect_time = max(taketime[j],infect_time);
            }
        }
        cout<<infect_count<<" "<<infect_time<<"\n";
    }
    return 0;
}