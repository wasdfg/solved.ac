#include<iostream>
#include<vector>

using namespace std;

int main(void){
    int n;
    cin>>n;
    vector<vector<long long>> jump(n,vector<long long>(n,0));
    vector<vector<long long>> dp(n,vector<long long>(n,0));
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            cin>>jump[i][j];
        }
    }
    dp[0][0] = 1;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            if(dp[i][j] == 0 || jump[i][j] == 0)
                continue;
            int x = jump[i][j];
            if(i+x < n){
                dp[i+x][j]+=dp[i][j];
            }
            if(j+x < n){
                dp[i][j+x]+=dp[i][j]; 
            }
        }
    }
    cout<<dp[n-1][n-1];
    return 0;
}