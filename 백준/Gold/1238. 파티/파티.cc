#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<pair<int,int>> route[1001];
int N,M,X;

int main(void){
    int a,b,c,toX,tohome,result = 0;
    cin>>N>>M>>X;
    vector<int> home(N+1,987654321);
    for(int i = 0;i < M;i++){
        cin>>a>>b>>c;
        route[a].push_back({b,c});
    }
    for(int i = 1;i <= N;i++){
        home.assign(N+1,987654321);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,i});
        home[i] = 0;
        while(!pq.empty()){
            int cost = pq.top().first;
            int now = pq.top().second;
            pq.pop();
            if(now == X){
                toX = home[now];
                break;
            }
            for(int i = 0;i < route[now].size();i++){
                int ncost = cost+route[now][i].second;
                int next = route[now][i].first;
                if(ncost < home[next]){
                    home[next] = ncost;
                    pq.push({ncost,next});
                }
            }
        }
        while(!pq.empty()){
            pq.pop();
        }
        home.assign(N+1,987654321);
        pq.push({0,X});
        home[X] = 0;
        while(!pq.empty()){
            int cost = pq.top().first;
            int now = pq.top().second;
            pq.pop();
            if(now == i){
                tohome = home[now];
                break;
            }
            for(int i = 0;i < route[now].size();i++){
                int ncost = cost+route[now][i].second;
                int next = route[now][i].first;
                if(ncost < home[next]){
                    home[next] = ncost;
                    pq.push({ncost,next});
                }
            }
        }
        if(toX+tohome > result){
            result = toX+tohome;
        }
    }
    cout<<result;
    return 0;
}