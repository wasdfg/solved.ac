#include<iostream>
#include<vector>

using namespace std;

int main(void){
    int n;
    cin>>n;
    vector<int> dp(n,0);
    dp[0] = 3;
    dp[1] = 7;
    for(int i = 2;i < n;i++){
        dp[i] = (dp[i-1]*2%9901)+dp[i-2]%9901;
    }
    cout<<dp[n-1]%9901;
    return 0;
}