#include<iostream>
#include<vector>
#define ull unsigned long long

using namespace std;

int main(void){
    int t,n,m;
    vector<vector<ull>> dp(31,vector<ull>(31,1));
    cin>>t;
    for(int i = 1;i < 31;i++){
        dp[i][1] = i;
        dp[i][i] = 1;
    }
    for(int i = 2;i < 31;i++){
        for(int j = 1;j < 31;j++){
            if(i > j){
                dp[i][j] = dp[i-1][j-1]+dp[i-1][j];
            }
        }
    }
    for(int i = 0;i < t;i++){
        cin>>n>>m;
        cout<<dp[m][n]<<endl;
    }
    return 0;
}