#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(void){
    int n,a,b;
    cin>>n;
    vector<int> tree[n+1];
    vector<int> parent(n+1,0);
    for(int i = 0;i < n-1;i++){
        cin>>a>>b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    queue<int> togo;
    togo.push(1);
    parent[1] = 1;
    while(!togo.empty()){
        int x = togo.front();
        togo.pop();
        for(int i = 0;i < tree[x].size();i++){
            if(parent[tree[x][i]] == 0){
                parent[tree[x][i]] = x;
                togo.push(tree[x][i]);
            }
        }
    }
    for(int i = 2;i < n+1;i++){
        cout<<parent[i]<<"\n";
    }
    return 0;
}