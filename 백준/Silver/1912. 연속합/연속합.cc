#include<iostream>
#include<vector>

using namespace std;

int main(void){
    long long n,number,maxi;
    cin>>n;
    vector<long long> sum;
    vector<long long> result(n,0);
    for(int i = 0;i < n;i++){
        cin>>number;
        sum.push_back(number);
    }
    result[0] = sum[0];
    maxi = result[0];
    for(int i = 1;i < n;i++){
        maxi = max(maxi,result[i] = max(sum[i]+result[i-1],sum[i])); 
    }
    cout<<maxi;
    return 0;
}