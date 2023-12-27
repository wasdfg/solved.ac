#include<iostream>
#include<vector>
#include<queue>

using namespace std;
pair<int,int> pos[100000];
vector<bool> visited(100000,0);

int main(void){
    int N,K;
    cin>>N>>K;
    for(int i = 0;i < 100001;i++){
        pos[i].second = 9999999;
    }
    queue<int> togo;
    togo.push(N);
    pos[N].second = 0;
    visited[N] = true;
    while(!togo.empty()){
        int x = togo.front();
        int y = pos[x].second;
        togo.pop();
        if(x == K){
            break;
        }
        if(x*2 <= 100000 && visited[x*2] == false){
            visited[x*2] = true;
            pos[x*2].second = y;
            togo.push(x*2);
        }
        if(x-1 >= 0 && visited[x-1] == false){
            visited[x-1] = true;
            pos[x-1].second = y+1;
            togo.push(x-1);
        }
        if(x+1 <= 100000 && visited[x+1] == false){
            visited[x+1] = true;
            pos[x+1].second = y+1;
            togo.push(x+1);
        }
    }
    cout<<pos[K].second;
}