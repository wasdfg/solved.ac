#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<int> city[300001];
queue<int> q;
vector<int> dist;

int main(void){
    int N,M,K,X,a,b;
    cin>>N>>M>>K>>X;
    dist.assign(N+1,987654321);
    for(int i = 0;i < M;i++){
        cin>>a>>b;
        city[a].push_back(b);
    }
    q.push(X);
    dist[X] = 0;
    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(int i = 0;i < city[now].size();i++){
            int next = city[now][i];
            if(dist[next] > dist[now] +1){
                dist[next] = dist[now]+1;
                q.push(next);
            }
        }
    }
    bool check = false;
    for(int i = 1;i < dist.size();i++){
        if(dist[i] == K){
            check = true;
            cout<<i<<"\n";
        }
    }
    if(check == false){
        cout<<"-1\n";
    }
    return 0;
}