#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void){
    int n,result = 1000000000;
    cin>>n;
    vector<vector<int>> rgb(n,vector<int>(3,0));
    vector<vector<int>> dp(n,vector<int>(3,0));
    for(int i = 0;i < n;i++){
        cin>>rgb[i][0]>>rgb[i][1]>>rgb[i][2];
    }
    for(int a = 0;a < 3;a++){
        for(int b = 0;b < 3;b++){
            if(b == a){
                dp[0][b] = rgb[0][b];
            }
            else{
                dp[0][b] = 987654321;
            }
        }
        for(int i = 1;i < n;i++){
            dp[i][0] = rgb[i][0]+min(dp[i-1][1],dp[i-1][2]);
            dp[i][1] = rgb[i][1]+min(dp[i-1][0],dp[i-1][2]);
            dp[i][2] = rgb[i][2]+min(dp[i-1][1],dp[i-1][0]);
        }
        for(int i = 0;i < 3;i++){
            if(i != a){
                result = min(result,dp[n-1][i]);
            }
        }
    }
    cout<<result;
    return 0;
}