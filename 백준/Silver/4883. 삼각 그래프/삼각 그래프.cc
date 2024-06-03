#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void){
    int a,k = 1;
    while(cin>>a){
        if(a == 0){
            break;
        }
        vector<vector<int>> dp(a,vector<int>(3,0));
        for(int i = 0;i < a;i++){
            cin>>dp[i][0]>>dp[i][1]>>dp[i][2];
        }
        dp[0][0] = 2147483647;
        dp[0][2]+=dp[0][1];
        for(int i = 1;i < a;i++){
            dp[i][0] += min(dp[i-1][1],dp[i-1][0]);
            dp[i][1] += min({dp[i-1][0],dp[i-1][1],dp[i-1][2],dp[i][0]});
            dp[i][2] += min({dp[i][1],dp[i-1][1],dp[i-1][2]});
        }
        cout<<k<<". "<<dp[a-1][1]<<endl;
        k++;
    }
    return 0;
}