#include<iostream>
#include<vector>

using namespace std;

vector<bool> isprime(4000001,1);

int main(void){
    int n,start = 0,end = 0,sum,result = 0;
    vector<int> check;
    cin>>n;
    isprime[0] = 0;
    isprime[1] = 0;
    if(n > 1){
        for(int i = 2;i <= n;i++){
            if(isprime[i] == 1){
                check.push_back(i);
            }
            for(int j = 2;i * j <= n;j++){
                isprime[i*j] = 0;
            }
        }
        sum = check[0];
    }
    else{
        sum = 0;
    }
    while(start <= end && end < check.size()){
        if(sum == n){
            result++;
        }
        if(sum >= n){
            sum-=check[start];
            start++;
        }
        else{
            end++;
            sum+=check[end];
        }
    }
    cout<<result;
    return 0;
}