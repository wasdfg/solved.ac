#include<iostream>
#include<vector>

using namespace std;

int main(void){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n,t;
    cin>>t;
    vector<vector<long long>> dp(100001,vector<long long>(4,0));
    dp[1][1] = 1;
    dp[2][2] = 1;
    dp[3][1] = 1;
    dp[3][2] = 1;
    dp[3][3] = 1;
    for(int i = 4;i < 100001;i++){
            dp[i][1] = (dp[i-1][2]+dp[i-1][3]) % 1000000009;
            dp[i][2] = (dp[i-2][1]+dp[i-2][3]) % 1000000009;
            dp[i][3] = (dp[i-3][1]+dp[i-3][2]) % 1000000009;
    }
    for(int a = 0;a < t;a++){
        cin>>n;
        cout<<(dp[n][1]+dp[n][2]+dp[n][3]) % 1000000009<<"\n";
    }
    return 0;
}