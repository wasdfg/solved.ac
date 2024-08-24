#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int main(void){
    int n,m,a,b,answer = 0;
    cin>>n>>m;
    vector<int> computer[n+1];
    vector<int> visited(n+1,0);
    vector<int> result(n+1,0);
    for(int i = 0;i < m;i++){
        cin>>a>>b;
        computer[a].push_back(b);
    }
    for(int i = 1;i <= n;i++){
        visited[i] = 1;
        queue<int> togo;
        togo.push(i);
        while(!togo.empty()){
            int x = togo.front();
            togo.pop();
            for(int i = 0;i < computer[x].size();i++){
                if(visited[computer[x][i]] == 0){
                    visited[computer[x][i]] = 1;
                    result[computer[x][i]]++;
                    togo.push(computer[x][i]);
                }
            }
        }
        visited.assign(n+1,0);
    }
    for(int i = 1;i <= n;i++){
        answer = max(answer,result[i]);
    }
    for(int i = 1;i <= n;i++){
        if(result[i] == answer){
            cout<<i<<" ";
        }
    }
    return 0;
}