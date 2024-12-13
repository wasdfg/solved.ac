#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void){
    int n,a,b,c;
    cin>>n;
    vector<vector<int>> dp(n+1,vector<int>(3,0));
    for(int i = 1;i < n+1;i++){
        cin>>a>>b>>c;
        dp[i][0] = min(dp[i-1][1],dp[i-1][2])+a;
        dp[i][1] = min(dp[i-1][0],dp[i-1][2])+b;
        dp[i][2] = min(dp[i-1][0],dp[i-1][1])+c;
    }
    cout<<min({dp[n][0],dp[n][1],dp[n][2]});
    return 0;
}