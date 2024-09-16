#include<iostream>
#include<vector>

using namespace std;

int main(void){
    int n,result = 0;
    cin>>n;
    vector<int> num(n,0);
    vector<int> dp(n,0);
    for(int i = 0;i < n;i++){
        cin>>num[i];
        dp[i] = num[i];
    }
    for(int i = 0;i < n;i++){
        for(int j = 0;j < i;j++){
            if(num[i] > num[j] && dp[i] < dp[j]+num[i]){
                dp[i] = dp[j]+num[i];
            }
        }
        result = max(dp[i],result);
    }
    cout<<result;
    return 0;
}