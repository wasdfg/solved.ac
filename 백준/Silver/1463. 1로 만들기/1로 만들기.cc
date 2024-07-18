#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void){
    int x;
    cin>>x;
    vector<int> dp(x+1,0);
    dp[2] = 1;
    dp[3] = 1;
    for(int i = 4;i < x+1;i++){
        if(i % 6 == 0){
            dp[i] = min({dp[i/2]+1,dp[i/3]+1,dp[i-1]});
        }
        else if(i % 2 == 0){
            dp[i] = min(dp[i/2]+1,dp[i-1]+1);
        }
        else if(i % 3 == 0){
            dp[i] = min(dp[i/3]+1,dp[i-1]+1);
        }
        else{
            dp[i] = dp[i-1]+1;
        }
    }
    cout<<dp[x];
    return 0;
}