#include<iostream>
#include<vector>

using namespace std;

int main(void){
    int n,result = 0;
    cin>>n;
    vector<vector<int>> dp(n,vector<int>(10,1));
    for(int i = 1;i < n;i++){
        for(int j = 1;j < 10;j++){
            dp[i][j] = (dp[i-1][j] % 10007) + (dp[i][j-1] % 10007);
        }
    }
    for(int i = 0;i < 10;i++){
        result+=dp[n-1][i];
    }
    cout<<result%10007;
    return 0;
}