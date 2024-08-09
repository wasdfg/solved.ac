#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(void){
    int n,m,k,x,a,b;
    cin>>n>>m>>k>>x;
    vector<int> city[n+1];
    vector<int> visited(n+1,1000000000);
    queue<int> togo;
    for(int i = 0;i < m;i++){
        cin>>a>>b;
        city[a].push_back(b);
    }
    visited[x] = 0;
    togo.push(x);
    while(!togo.empty()){
        int now = togo.front();
        togo.pop();
        for(int i = 0;i < city[now].size();i++){
            if(visited[city[now][i]] > visited[now]+1){
                visited[city[now][i]] = visited[now]+1;
                togo.push(city[now][i]);
            }
        }
    }
    bool no = true;
    for(int i = 1;i < n+1;i++){
        if(visited[i] == k){
            no = false;
            cout<<i<<endl;
        }
    }
    if(no == true){
        cout<<"-1";
    }
    return 0;
}