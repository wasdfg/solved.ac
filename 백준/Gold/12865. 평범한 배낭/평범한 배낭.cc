#include<iostream>
#include<vector>

using namespace std;

int main(void){
    int n,k;
    cin>>n>>k;
    vector<int> weight(n,0);
    vector<int> value(n,0);
    vector<vector<int>> dp(n+1,vector<int>(k+1,0));
    for(int i = 0;i < n;i++){
        cin>>weight[i]>>value[i];
    }
    for(int i = 1;i < n+1;i++){
        for(int j = 1;j < k+1;j++){
            if(j >= weight[i-1]){
                dp[i][j] = max(dp[i-1][j],dp[i-1][j-weight[i-1]]+value[i-1]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    cout<<dp[n][k];
    return 0;
}