#include<iostream>
#include<vector>

using namespace std;

int main(void){
    long long t,n,sum = 0;
    vector<vector<long long>> dp(64,vector<long long>(10,0));
    cin>>t;
    for(int i = 0;i < 10;i++){
        dp[0][i] = 1;
    }
    for(int i = 1;i < 64;i++){
        for(int j = 0;j < 10;j++){
            for(int k = j;k <= 9;k++){
                dp[i][j] += dp[i-1][k];
            }
        }
    }
    for(int i = 0;i < t;i++){
        cin>>n;
        sum = 0;
        for(int j = 0;j < 10;j++){
            sum+=dp[n-1][j];
        }
        cout<<sum<<endl;
    }
    return 0;
}