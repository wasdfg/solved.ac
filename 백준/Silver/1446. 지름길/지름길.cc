#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void){
    int n,d,a,b,c;
    cin>>n>>d;
    vector<pair<int,int>> shortcut[d+1];
    vector<int> dp(d+1,1000000000);
    for(int i = 0;i < n;i++){
        cin>>a>>b>>c;
        if(a < d && (b <= d || b-a >= c)){
            shortcut[a].push_back({b,c});
        }
    }
    dp[0] = 0;
    for(int i = 0;i < d+1;i++){
        dp[i+1] = min(dp[i]+1,dp[i+1]);
        for(int j = 0;j < shortcut[i].size();j++){
            dp[shortcut[i][j].first] = min(dp[shortcut[i][j].first],dp[i]+shortcut[i][j].second);
        }
    }
    cout<<dp[d];
    return 0;
}