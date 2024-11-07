#include<iostream>
#include<vector>

using namespace std;

int main(void){
    int n,t,m;
    cin>>t;
    for(int i = 0;i < t;i++){
        cin>>n;
        vector<int> coin(n,0);
        for(int j = 0;j < n;j++){
            cin>>coin[j];
        }
        cin>>m;
        vector<int> dp(m+1,0);
        dp[0] = 1;
        for(int a = 0;a < n;a++){
            for(int b = coin[a];b < m+1;b++){
                dp[b]+=dp[b-coin[a]];
            }
        }
        cout<<dp[m]<<endl;
    }
    return 0;
}