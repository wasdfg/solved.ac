#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void){
    int n,result = 0,check = 0;
    cin>>n;
    vector<int> dp(n,0);
    vector<int> num(n,0);
    vector<int> answer;
    for(int i = 0;i < n;i++){
        cin>>num[i];
    }
    for(int i = 0;i < n;i++){
        for(int j = 0;j < i;j++){
            if(num[i] > num[j]){
                dp[i] = max(dp[j]+1,dp[i]);
            }
            result = max(result,dp[i]);
        }
    }
    cout<<result+1<<endl;
    for(int i = n-1;i >= 0;i--){
        if(dp[i] == result){
            answer.push_back(num[i]);
            result--;
        }
    }
    reverse(answer.begin(),answer.end());
    for(auto a:answer){
        cout<<a<<" ";
    }
    return 0;
}