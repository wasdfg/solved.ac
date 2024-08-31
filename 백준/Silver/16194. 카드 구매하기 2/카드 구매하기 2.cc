#include<iostream>
#include<vector>

using namespace std;

int main(void){
    int n;
    cin>>n;
    vector<int> card(n+1,0);
    vector<int> dp(n+1,0);
    for(int i = 1;i <= n;i++){
        cin>>card[i];
    }
    for(int i = 1;i <= n;i++){
        dp[i] = card[i];
        for(int j = 1;j <= i;j++){
            dp[i] = min(dp[i],card[j]+dp[i-j]);
        }
    }
    cout<<dp[n];
    return 0;
}