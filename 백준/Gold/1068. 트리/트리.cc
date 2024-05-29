#include <iostream>
#include <vector>
#include<queue>

using namespace std;

vector<vector<int>> leaf;

int main(void){
    int n,x,cut,head,child,answer = 0;
    cin>>n;
    leaf.resize(n,vector<int>());
    vector<bool> visited(n,0);
    queue<int> togo;
    for(int i = 0;i < n;i++){
        cin>>x;
        if(x != -1){
            leaf[x].push_back(i);
        }
        else{
            head = i;
        }
    }
    cin>>cut;
    togo.push(head);
    visited[head] = 1;
    visited[cut] = 1;
    while(!togo.empty()){
        int next = togo.front();
        togo.pop();
        child = 0;
        for(int i = 0;i < leaf[next].size();i++){
            if(visited[leaf[next][i]] == 0){
                child++;
                visited[leaf[next][i]] = 1;
                togo.push(leaf[next][i]);
            }
        }
        if(child == 0){
            answer++;
        }
    }
    if(head == cut){
        answer = 0;
    }
    cout<<answer;
    return 0;
}