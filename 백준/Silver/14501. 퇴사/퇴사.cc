#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void){
    int n;
    cin>>n;
    vector<vector<int>> counsel(n,vector<int>(2,0));
    vector<int> dp(n+1,0);
    for(int i = 0;i < n;i++){
        cin>>counsel[i][0]>>counsel[i][1];
    }
    for(int i = n-1;i >= 0;i--){
        if(counsel[i][0]+i > n){
            dp[i] = dp[i+1];
        }
        else{
            dp[i] = max(counsel[i][1]+dp[i+counsel[i][0]],dp[i+1]);
        }
    }
    cout<<*max_element(dp.begin(),dp.end());
    return 0;
}