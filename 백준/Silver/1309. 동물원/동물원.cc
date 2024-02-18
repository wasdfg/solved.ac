#include<iostream>
#include<vector>

using namespace std;

int main(void){
    int N;
    vector<int> dp;
    cin>>N;
    dp.assign(N,0);
    dp[0] = 3;
    if(N > 1){
    dp[1] = 7;
        for(int i = 2;i < N;i++){
            dp[i] = (((dp[i-1] % 9901)*2 + (dp[i-2] % 9901)) % 9901); 
        }
    }
    cout<<dp[N-1]%9901;
    return 0;
}