#include<iostream>
#include<vector>
typedef unsigned long long ull;

using namespace std;

int main(void){
    int n,k;
    cin>>n>>k;
    vector<vector<ull>> dp(n+1,vector<ull>(n+1,1));
    for(int i = 1;i < n+1;i++){
        for(int j = 1;j < i;j++){
            dp[i][j] = (dp[i-1][j] % 10007)+(dp[i-1][j-1] % 10007);
        }
    }
    cout<<dp[n][k] % 10007;
    return 0;
}