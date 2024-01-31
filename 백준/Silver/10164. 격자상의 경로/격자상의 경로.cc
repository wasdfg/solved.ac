#include<iostream>
#include<vector>

using namespace std;

int main(void){
    int N,M,k;
    cin>>N>>M>>k;
    vector<vector<int>> route(N,vector<int>(M,1));
    for(int i = 1;i < N;i++){
        for(int j = 1;j < M;j++){
            route[i][j] = route[i-1][j] + route[i][j-1];
        }
    }
    if(k == 0)
        cout<<route[N-1][M-1];
    else{
        cout<<route[k/M][k%M-1]*route[N-(k/M)][M-(k%M)-1];
    }
    return 0;
}