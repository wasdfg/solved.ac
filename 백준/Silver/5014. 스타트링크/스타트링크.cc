#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(void){
    int f,s,g,u,d;
    cin>>f>>s>>g>>u>>d;
    vector<int> stair(f+1,-1);
    queue<pair<int,int>> togo;
    stair[s] = 0;
    togo.push({s,0});
    while(!togo.empty()){
        int now = togo.front().first;
        int cost = togo.front().second;
        togo.pop();
        if(now == g){
            break;
        }
        if(now+u <= f && stair[now+u] == -1){
            stair[now+u] = cost+1;
            togo.push({now+u,cost+1});
        }
        if(now-d >= 1 && stair[now-d] == -1){
            stair[now-d] = cost+1;
            togo.push({now-d,cost+1});
        }
    }
    if(stair[g] >= 0){
        cout<<stair[g];
    }
    else{
        cout<<"use the stairs";
    }
    return 0;
}