#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void){
    int n,k;
    cin>>n;
    vector<vector<int>> jump(20,vector<int>(2,0));
    vector<vector<int>> dp(20,vector<int>(2,1000000000));
    for(int i = 0;i < n-1;i++){
        cin>>jump[i][0]>>jump[i][1];
    }
    cin>>k;
    dp[0][0] = 0;
    dp[1][0] = jump[0][0];
    dp[2][0] = min(dp[1][0]+jump[1][0],dp[0][0]+jump[0][1]);
    for(int i = 3;i < n;i++){
        dp[i][0] = min(dp[i-1][0]+jump[i-1][0],dp[i-2][0]+jump[i-2][1]);
        dp[i][1] = min({dp[i-1][1]+jump[i-1][0],dp[i-2][1]+jump[i-2][1],dp[i-3][0]+k});
    }
    cout<<min(dp[n-1][0],dp[n-1][1]);
    return 0;
}