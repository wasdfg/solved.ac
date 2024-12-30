#include<iostream>
#include<vector>

using namespace std;

int main(void){
    int n;
    cin>>n;
    vector<int> dp(n+1,0);
    for(int i = 1;i < n+1;i++){
        dp[i] = dp[i-1]+1;
        for(int j = 1;j * j <= i;j++){
            dp[i] = min(dp[i],dp[i-j*j]+1);
        }
    }
    cout<<dp[n];
    return 0;
}