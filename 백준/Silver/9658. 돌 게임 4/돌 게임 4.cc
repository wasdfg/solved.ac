#include<iostream>
#include<vector>

using namespace std;

int main(void){
    int n;
    cin>>n;
    vector<int> dp(n+1,0);
    dp[1] = 1;
    dp[3] = 1;
    for(int i = 8;i <= n;i++){
        if(i % 7 == 1 || i % 7 == 3){
            dp[i] = 1;
        }
    }
    dp[n] == 0?cout<<"SK":cout<<"CY";
    return 0;
}