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
            if(jump[i][j] == 0 || dp[i][j] == 0){
                continue;
            }
            if(i+jump[i][j] < n){
                dp[i+jump[i][j]][j]+=dp[i][j];
            }
            if(j+jump[i][j] < n){
                dp[i][j+jump[i][j]]+=dp[i][j];
            }
        }
    }
    cout<<dp[n-1][n-1];
    return 0;
}