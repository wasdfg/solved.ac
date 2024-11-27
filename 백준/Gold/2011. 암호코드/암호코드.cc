#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main(void){
    string n;
    cin>>n;
    vector<long long> dp(n.length()+1,0);
    dp[0] = 1;
    dp[1] = 1;
    for(int i = 2;i < n.length()+1;i++){
        if((n[i-1]-'0') != 0){
            dp[i] = (dp[i-1] + dp[i]) % 1000000;
        }
        int tmp = (n[i-1]-'0')+(n[i-2]-'0')*10;
        if(tmp > 9 && tmp < 27){
            dp[i] = (dp[i-2] + dp[i]) % 1000000;
        }
    }
    if((n[0]-'0') == 0){
        cout<<0;
    } 
    else{
        cout<<dp[n.length()] % 1000000;
    }
    return 0;
}