#include<iostream>
#include<vector>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,t;
    cin>>t;
    vector<vector<long long>> dp(100001,vector<long long>(3,0));
    dp[1][0] = 1;
    dp[2][1] = 1;
    dp[3][0] = dp[3][1] = dp[3][2] = 1;
    for(int i = 4;i < 100001;i++){
        dp[i][0] = (dp[i-1][1]+dp[i-1][2]) % 1000000009;
        dp[i][1] = (dp[i-2][0]+dp[i-2][2]) % 1000000009 ;
        dp[i][2] = (dp[i-3][0]+dp[i-3][1]) % 1000000009;
    }
    for(int i = 0;i < t;i++){
        cin>>n;
        cout<<(dp[n][0]+dp[n][1]+dp[n][2]) % 1000000009<<"\n";
    }
    return 0;
}