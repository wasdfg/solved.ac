#include<iostream>
#include<vector>

using namespace std;

int main(void){
    int max = -10000001,N,K,x,sum = 0;
    vector<int> num;
    cin>>N>>K;
    for(int i = 0;i < N;i++){
        cin>>x;
        num.push_back(x);
    }
    for(int i = 0;i < K;i++){
        sum+=num[i];
    }
    if(sum > max)
        max = sum;
    for(int i = 0;i < N - K;i++){
        sum -= num[i];
        sum += num[i+K];
        if(sum > max){
            max = sum;
        }
    }
    cout<<max<<endl;
}