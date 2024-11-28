#include<iostream>
#include<vector>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m,s,e;
    cin>>n;
    vector<vector<bool>> dp(n,vector<bool>(n,0));
    vector<int> arr(n,0);
    for(int i = 0;i < n;i++){
        cin>>arr[i];
    }
    for(int i = 0;i < n-1;i++){
        dp[i][i] = 1;
        if(arr[i] == arr[i+1]){
            dp[i][i+1] = 1;
        }
    }
    dp[n-1][n-1] = 1;
    for(int i = n-1;i >= 0;i--){
        for(int j = i+2;j <= n;j++){
            if(arr[i] == arr[j] && dp[i+1][j-1] == 1){
                dp[i][j] = 1;
            }
        }
    }
    cin>>m;
    for(int i = 0;i < m;i++){
        cin>>s>>e;
        cout<<dp[s-1][e-1]<<"\n";
    }
    return 0;
}