#include<iostream>
#include<vector>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m,a,b,c,d;
    cin>>n>>m;
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    for(int i = 1;i < n+1;i++){
        for(int j = 1;j < n+1;j++){
            cin>>dp[i][j];
            dp[i][j] += dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
        }
    }
    for(int i = 0;i < m;i++){
        cin>>a>>b>>c>>d;
        cout<<dp[c][d]-dp[c][b-1]-dp[a-1][d]+dp[a-1][b-1]<<"\n";
    }
    return 0;
}