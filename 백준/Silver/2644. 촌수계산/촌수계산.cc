#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;
vector<int> chon[101];
vector<int> check(101,0);
vector<bool> visited(101,0);

int main(void){
    int n,s,e,m,x,y;
    bool nochon = true;
    queue<int> togo;
    cin>>n>>s>>e>>m;
    for(int i = 0;i < m;i++){
        cin>>x>>y;
        chon[x].push_back(y);
        chon[y].push_back(x);
    }
    for(int i = 0;i < 101;i++){
        sort(chon[i].begin(),chon[i].end());
    }
    togo.push(s);
    visited[s] = 1;
    check[s] = 1;
    while(!togo.empty()){
        int a = togo.front();
        togo.pop();
        if(a == e){
            nochon = false;
            break;
        }
        for(int i = 0;i < chon[a].size();i++){
            if(visited[chon[a][i]] == false){
                visited[chon[a][i]] = true;
                check[chon[a][i]] = check[a]+1;
                togo.push(chon[a][i]);
            }
        }
    }
    if(nochon == false){
        cout<<check[e]-1;
    }
    else{
        cout<<"-1";
    }
    return 0;
}