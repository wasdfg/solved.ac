#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(void){
    int n,k;
    cin>>n>>k;
    vector<int> pos(100001,100000000);
    vector<bool> visited(100001,0);
    queue<int> now;
    now.push(n);
    visited[n] = 1;
    pos[n] = 0;
    while(!now.empty()){
        int here = now.front();
        now.pop();
        if(here == k){
            break;
        }
        if(here+1 < 100001 && visited[here+1] == 0){
            pos[here+1] = min(pos[here+1],pos[here]+1);
            visited[here+1] = 1;
            now.push(here+1);
        }
        if(here-1 >= 0 && visited[here-1] == 0){
            pos[here-1] = min(pos[here-1],pos[here]+1);
            visited[here-1] = 1;
            now.push(here-1);
        }
        if(here*2 < 100001 && visited[here*2] == 0){
            pos[here*2] = min(pos[here*2],pos[here]+1);
            visited[here*2] = 1;
            now.push(here*2);
        }
    }
    cout<<pos[k];
    return 0;
}