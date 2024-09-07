#include<iostream>
#include<vector>

using namespace std;

int main(void){
    long long t,n,sum = 0,check;
    vector<vector<long long>> dp(64,vector<long long>(10,0));
    cin>>t;
    for(int i = 0;i < 10;i++){
        dp[0][i] = 1;
        sum+=dp[0][i];
    }
    for(int i = 1;i < 64;i++){
        check = sum;
        sum = 0;
        for(int j = 0;j < 10;j++){
            dp[i][j] = check;
            sum+=check;
            check-=dp[i-1][j];   
        }
    }
    for(int i = 0;i < t;i++){
        cin>>n;
        sum = 0;
        for(int j = 0;j < 10;j++){
            sum+=dp[n-1][j];
        }
        cout<<sum<<endl;
    }
    return 0;
}