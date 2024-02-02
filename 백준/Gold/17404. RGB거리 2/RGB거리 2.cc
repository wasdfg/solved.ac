#include<iostream>
#include<vector>

using namespace std;

int main(void){
    int N,ans = 987654321;
    cin>>N;
    vector<vector<int>> RGB(N,vector<int>(3,0));
    vector<vector<int>> dp(N,vector<int>(3,0));
    for(int i = 0;i < N;i++){
        cin>>RGB[i][0]>>RGB[i][1]>>RGB[i][2];
    }
    for(int a = 0;a < 3;a++){
        for(int i = 0; i < 3; i++){
			if(i == a) 
				dp[0][i] = RGB[0][i];
			else 
				dp[0][i] = 987654321;
		}
        for(int i = 1;i < N;i++){
            dp[i][0] = min(dp[i-1][1],dp[i-1][2])+RGB[i][0];
            dp[i][1] = min(dp[i-1][0],dp[i-1][2])+RGB[i][1];
            dp[i][2] = min(dp[i-1][0],dp[i-1][1])+RGB[i][2];
        }
        for (int i = 0; i <= 2; i++){
			if(i == a){ 
                continue;
            }
			else 
                ans = min(ans, dp[N-1][i]);
		}
    }
    cout<<ans;
    return 0;
}