#include<iostream>
#include<vector>

using namespace std;

int main(void){
    long long N,M,k,x,y;
    cin>>N>>M>>k;
    vector<vector<long long>> route(N,vector<long long>(M,1));
    for(int i = 1;i < N;i++){
        for(int j = 1;j < M;j++){
            route[i][j] = route[i-1][j] + route[i][j-1];
        }
    }
    if(k == 0)
        cout<<route[N-1][M-1];
    else{
        if(k%M != 0){
			y=k%M;
			x=k/M+1;
		}
		else{
			x=k/M;
			y=M;
		}
        cout<<route[x-1][y-1]*route[N-x][M-y];
    }
    return 0;
}