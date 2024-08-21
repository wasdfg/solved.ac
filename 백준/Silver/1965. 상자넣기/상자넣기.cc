#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void){
    int n,result = 1;
    cin>>n;
    vector<int> num(n,0);
    vector<int> dp(n,1);
    for(int i = 0;i < n;i++){
        cin>>num[i];
    }
    for(int i = 0;i < n;i++){
        for(int j = 0;j < i;j++){
            if(num[j] < num[i] && dp[i] < dp[j]+1){
                dp[i] = dp[j]+1;
            }
        }
        result = max(result,dp[i]);
    }
    cout<<result;
    return 0;
}