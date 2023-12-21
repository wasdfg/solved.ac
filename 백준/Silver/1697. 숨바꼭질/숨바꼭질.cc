#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<int> on(100001,0);
vector<bool> visited(100001,0);

int main(void){
    int N,K;
    cin>>N>>K;
    queue<int> togo;
    visited[N] = true;
    on[N] = 1;
    togo.push(N);
    while(!togo.empty()){
        int x = togo.front();
        togo.pop();
        if(x == K){
            break;
        }
        if(x - 1 >= 0){
            if(visited[x-1] == false){
                visited[x-1] = true;
                on[x-1] = on[x] + 1;
                togo.push(x-1);
            }
        }
        if(x + 1 <= 100000){
            if(visited[x+1] == false){
                visited[x+1] = true;
                on[x+1] = on[x] +1;
                togo.push(x+1);
            }
        }
        if(x * 2 <= 100000){
            if(visited[x*2] == false){
                visited[x*2] = true;
                on[x*2] = on[x] + 1;
                togo.push(x*2);
            }
        }
    }
    cout<<on[K]-1;
    return 0;
}