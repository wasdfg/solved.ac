#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> dp;
vector<int> weight;
vector<int> value;

int main(void){
    int n,k;
    cin>>n>>k;
    weight.assign(n+1,0);
    value.assign(n+1,0);
    dp.assign(n+1,vector<int>(k+1,0));
    for(int i = 1;i <= n;i++){
        cin>>weight[i]>>value[i];
    }
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= k;j++){
            if(j >= weight[i]){
                dp[i][j] = max(dp[i-1][j],dp[i-1][j-weight[i]]+value[i]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    cout<<dp[n][k];
    return 0;
}