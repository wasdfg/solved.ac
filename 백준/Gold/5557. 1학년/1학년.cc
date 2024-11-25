#include<iostream>
#include<vector>

using namespace std;

int main(void){
    long long n,num;
    cin>>n;
    vector<vector<long long>> dp(n,vector<long long>(21,0));
    for(long long i = 0;i < n;i++){
        cin>>num;
        if(i == 0){
            dp[0][num] = 1;
            continue;
        }
        for(int j = 0;j < 21;j++){
            if(dp[i-1][j] == 0){
                continue;
            }
            if(j+num < 21){
                dp[i][j+num]+=dp[i-1][j];
            }
            if(j-num >= 0){
                dp[i][j-num]+=dp[i-1][j];
            }
        }
        if(i == n-1){
            cout<<dp[i-1][num];
        }
    }
    return 0;
}