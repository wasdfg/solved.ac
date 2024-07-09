#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void){
    int n;
    cin>>n;
    vector<vector<int>> rgb(n,vector<int>(3,0));
    vector<vector<int>> dp(n,vector<int>(3,0));
    for(int i = 0;i < n;i++){
        cin>>rgb[i][0]>>rgb[i][1]>>rgb[i][2];
    }
    for(int i = 0;i < 3;i++){
        dp[0][i] = rgb[0][i];
    }
    for(int i = 1;i < n;i++){
        dp[i][0] = rgb[i][0]+min(dp[i-1][1],dp[i-1][2]);
        dp[i][1] = rgb[i][1]+min(dp[i-1][0],dp[i-1][2]);
        dp[i][2] = rgb[i][2]+min(dp[i-1][0],dp[i-1][1]);
    }
    cout<<min({dp[n-1][0],dp[n-1][1],dp[n-1][2]});
    return 0;
}