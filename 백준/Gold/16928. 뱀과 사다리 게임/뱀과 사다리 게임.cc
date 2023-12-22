#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

vector<int> board(101,0);
vector<bool> visited(101,0);

int main(void){
    int N,M,a,b,x,y;
    cin>>N>>M;
    queue<pair<int,int>> togo;
    for(int i = 0;i < N;i++){
        cin>>a>>b;
        board[a] = b;

    }
    for(int i = 0;i < M;i++){
        cin>>a>>b;
        board[a] = b;
    }
    visited[1] = 1;
    togo.push({1,0});
    while(!togo.empty()){
        x = togo.front().first;
        y = togo.front().second;
        togo.pop();
        if(x == 100){
            break;
        }
        for(int i = 1;i <= 6;i++){
            if(visited[x+i] == 0 && x+i <= 100){
                if(board[x+i] == 0){
                    visited[x+i] = 1;
                    togo.push({x+i,y+1});
                }
                else{
                    visited[board[x+i]] = 1;
                    togo.push({board[x+i],y+1});
                }
            }
        }
    }
    cout<<y;
}