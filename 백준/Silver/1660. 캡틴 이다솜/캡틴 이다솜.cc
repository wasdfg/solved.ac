#include<iostream>
#include<vector>

using namespace std;

int main(void){
    int a = 1,b = 2,n,check = 0;
    cin>>n;
    vector<int> dp(n+1,1000000000);
    vector<int> fo;
    while(1){
        check+=a;
        if(check > n){
            break;
        }
        fo.push_back(check);
        dp[check] = 1;
        a+=b;
        b++;
    }
    for(int i = 0;i < fo.size();i++){
        for(int j = fo[i];j < n+1;j++){
            dp[j] = min(dp[j],dp[j-fo[i]]+1);
        }
    }
    cout<<dp[n];
    return 0;
}