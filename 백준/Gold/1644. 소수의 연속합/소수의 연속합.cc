#include<iostream>
#include<vector>

using namespace std;

vector<bool> isprime(4000001,1);
vector<int> check;

int main(void){
    int N,start = 0,end = 0,sum,result = 0;
    cin>>N;
    isprime[0] = 0;
    isprime[1] = 0;
    for(int i = 2;i <= 4000000;i++){
        if(isprime[i] == 1){
            check.push_back(i);
        }
        for(int j = 2;j * i <= 4000000;j++){
            isprime[j*i] = 0;
        }
    }
    sum = check.front();
    while(start <= end && end < check.size()){
        if(sum == N){
            result++;
        }
        if(sum > N){
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