#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<int> floor;

int main(void){
    int F,S,G,U,D;
    queue<int> togo;
    cin>>F>>S>>G>>U>>D;
    floor.resize(F+1,999999999);
    togo.push(S);
    floor[S] = 0;
    while(!togo.empty()){
        int now = togo.front();
        togo.pop();
        if(now == G){
            break;
        }
        if(now+U <= F && floor[now+U] == 999999999){
            floor[now+U] = min(floor[now+U]+floor[now],floor[now]+1);
            togo.push(now+U);
        }
        if(now-D >= 1 && floor[now-D] == 999999999){
            floor[now-D] = min(floor[now-D]+floor[now],floor[now]+1);
            togo.push(now-D);
        }
    }
    if(floor[G] == 999999999){
        cout<<"use the stairs";
    }
    else{
        cout<<floor[G];
    }
    return 0;
}