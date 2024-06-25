#include<iostream>
#include<vector>

using namespace std;

int main(void){
    long long t,n;
    cin>>t;
    vector<long long> dp(100,0);
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 1;
    for(long long i = 3;i < 100;i++){
        dp[i] = dp[i-2]+dp[i-3];
    }
    for(int i = 0;i < t;i++){
        cin>>n;
        cout<<dp[n-1]<<endl;
    }
    return 0;
}