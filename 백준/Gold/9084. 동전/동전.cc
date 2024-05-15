#include<iostream>
#include<vector>

using namespace std;

int main(void){
    int n,t,m;
    cin>>t;
    for(int i = 0;i < t;i++){
        cin>>n;
        vector<int> coin(21,0);
        vector<int> dp(10001,0);
        for(int j = 1;j <= n;j++){
            cin>>coin[j];
        }
        cin>>m;
        dp[0] = 1;
        for(int j = 1;j <= n;j++){
            for(int k = coin[j];k <= m;k++){
                dp[k]+=dp[k-coin[j]];
            }
        }
        cout<<dp[m]<<endl;
    }
    return 0;
}