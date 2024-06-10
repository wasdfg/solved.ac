#include<iostream>
#include<vector>

using namespace std;

int main(void){
    int n;
    cin>>n;
    vector<int> dp(n+1,0);
    for(int i = 1;i < n+1;i++){
        dp[i] = i;
    }
    for(int i = 2;i < n+1;i++){
        if(i % 3 == 0){
            dp[i] = min(dp[i/3],dp[i]);
        }
        if(i % 2 == 0){
            dp[i] = min(dp[i/2],dp[i]);
        }
        dp[i] = min(dp[i-1],dp[i])+1;
    }
    cout<<dp[n]-1<<endl;
    while(n != 0){
        cout<<n<<" ";
        if(dp[n] == dp[n-1]+1){
            n = n-1;
        }
        else if(n % 2 == 0 && dp[n] == dp[n/2]+1){
            n = n/2;
        }
        else if(n % 3 == 0 && dp[n] == dp[n/3]+1){
            n = n/3;
        }
    }
    return 0;
}