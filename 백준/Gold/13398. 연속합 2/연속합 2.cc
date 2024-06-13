#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void){
    int n,result;
    cin>>n;
    vector<vector<int>> dp(2,vector<int>(n,0));
    vector<int> num(n,0);
    for(int i = 0;i < n;i++){
        cin>>num[i];
    }
    dp[1][0] = num[0];
    dp[0][0] = num[0];
    result = num[0];
    for(int i = 1;i < n;i++){
        dp[0][i] = max(dp[0][i-1]+num[i],num[i]);
        dp[1][i] = max(dp[1][i-1]+num[i],dp[0][i-1]);
        result = max({result,dp[0][i],dp[1][i]}); 
    }
    cout<<result;
    return 0;
}