#include<iostream>
#include<vector>

using namespace std;

int main(void){
    int N,M,a,result = 1,num = 0;
    cin>>N>>M;
    vector<int> seat(N+1,1);
    seat[1] = 1;
    seat[2] = 2;
    for(int i = 3;i < N+1;i++){
        seat[i] = seat[i-1] + seat[i-2];
    }
    for(int i = 0;i < M;i++){
        cin>>a;
        result*=(seat[a-num-1]);
        num = a;
    }
    result*=(seat[N-num]);
    cout<<result;
    return 0;
}