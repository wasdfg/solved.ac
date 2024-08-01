#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void){
    int n;
    cin>>n;
    vector<int> stair(n+1,0);
    vector<int> dp(n+1,0);
    for(int i = 1;i < n+1;i++){
        cin>>stair[i];
    }
    dp[1] = stair[1];
    dp[2] = stair[1]+stair[2];  
    dp[3] = max(stair[2]+stair[3],stair[1]+stair[3]);
    for(int i = 4;i < n+1;i++){
        dp[i] = max(dp[i-3]+stair[i-1]+stair[i],dp[i-2]+stair[i]);
    }
    cout<<dp[n];
    return 0;
}