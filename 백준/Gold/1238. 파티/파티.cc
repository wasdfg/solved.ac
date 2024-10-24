#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<pair<int,int>> road[1000];
vector<int> pos;
int n,m,x,check;

void daijk(int start,int end){
    pos.assign(n,100000001);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,start});
    pos[start] = 0;
    while(!pq.empty()){
        int now = pq.top().second;
        int cost = pq.top().first;
        pq.pop();
        if(now == end){
            check = pos[now];
            break;
        }
        for(int i = 0;i < road[now].size();i++){
            int next = road[now][i].first;
            int ncost = road[now][i].second;
            if(pos[next] > cost+ncost){
                pos[next] = cost+ncost;
                pq.push({cost+ncost,next});
            }
        }
    }
}

int main(void){
    int a,b,c,tox,tohome,result = 0;
    cin>>n>>m>>x;
    for(int i = 0;i < m;i++){
        cin>>a>>b>>c;
        road[a-1].push_back({b-1,c});
    }
    for(int i = 0;i < n;i++){
        daijk(i,x-1);
        tox = check;
        daijk(x-1,i);
        tohome = check;
        result = max(result,tox+tohome);
    }
    cout<<result;
    return 0;
}