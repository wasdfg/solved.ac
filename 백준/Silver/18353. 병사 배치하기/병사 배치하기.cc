#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void){
    int n,m;
    cin>>n;
    vector<int> sol(n+1,0);
    vector<int> dp(n+1,1);
    dp[0] = 0;
    for(int i = 1;i < n+1;i++){
        cin>>sol[i];
        for(int j = 0;j < i;j++){
            if(sol[j] > sol[i]){
                dp[i] = max(dp[j]+1,dp[i]);
            }
        }
    }
    cout<<n-*max_element(dp.begin(),dp.end());
    return 0;
}