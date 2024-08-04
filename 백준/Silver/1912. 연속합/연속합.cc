#include<iostream>
#include<vector>

using namespace std;

int main(void){
    long long n,result = 0;
    cin>>n;
    vector<long long> num(n,0);
    vector<long long> dp(n,0);
    for(int i = 0;i < n;i++){
        cin>>num[i];
    }
    dp[0] = num[0];
    result = dp[0];
    for(int i = 1;i < n;i++){
        dp[i] = max(dp[i-1]+num[i],num[i]);
        result = max(dp[i],result);
    }
    cout<<result;
    return 0;
}