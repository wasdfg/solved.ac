#include <iostream>
#include <vector>
#include<queue>

using namespace std;

int n,result,no;
vector<int> graph[50];

void dfs(int now){
    if(now == no){
        return ;
    }
    bool check = true;
    for(int i = 0;i < graph[now].size();i++){
        if(graph[now][i] == no){
            continue;
        }
        check = false;
        dfs(graph[now][i]);
    }
    if(check){
        result++;
    }
}

int main(void){
    int x,start;
    cin>>n;
    for(int i = 0;i < n;i++){
        cin>>x;
        if(x == -1){
            start = i;
        }
        else{
            graph[x].push_back(i);
        }
    }
    cin>>no; 
    if(start != no){
        dfs(start);
    }
    cout<<result;
    return 0;
}