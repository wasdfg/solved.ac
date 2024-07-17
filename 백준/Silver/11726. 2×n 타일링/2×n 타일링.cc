#include<iostream>
#include<vector>

using namespace std;

int main(void){
    int n;
    cin>>n;
    vector<long long> dp(n,0);
    dp[0] = 1;
    dp[1] = 2;
    for(int i = 2;i < n;i++){
        dp[i] = ((dp[i-1] % 10007) + (dp[i-2] % 10007)) % 10007;
    }
    cout<<dp[n-1];
    return 0;
}