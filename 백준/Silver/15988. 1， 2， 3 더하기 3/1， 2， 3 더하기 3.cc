#include<iostream>
#include<vector>

using namespace std;

vector<long long> dp(1000000,0);

int main(void){
    int T,n;
    cin>>T;
    dp[0] = 1;
    dp[1] = 2;
    dp[2] = 4;
    for(int i = 3;i < 1000000;i++){
        dp[i] = (((dp[i-1]%1000000009+dp[i-2]%1000000009)%1000000009)+dp[i-3]%1000000009) % 10000000009;
    }
    for(int i = 0;i < T;i++){
        cin>>n;
        cout<<dp[n-1] % 1000000009<<endl;
    }
    return 0;
}