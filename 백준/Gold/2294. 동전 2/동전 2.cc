#include<iostream>
#include<vector>

using namespace std;

int main(void){
    int n,k;
    cin>>n>>k;
    vector<int> coin(n,0);
    vector<int> dp(k+1,100001);
    for(int i = 0;i < n;i++){
        cin>>coin[i];
    }
    dp[0] = 0;
    for(int i = 0;i < n;i++){
        for(int j = coin[i];j < k+1;j++){
            dp[j] = min(dp[j-coin[i]]+1,dp[j]);
        }
    }
    if(dp[k] == 100001){
        cout<<"-1";
    }
    else{
        cout<<dp[k];
    }
    return 0;
}