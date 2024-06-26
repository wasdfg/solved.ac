#include<iostream>
#include<vector>

using namespace std;

int main(void){
    int N,a,count;
    cin>>N;
    vector<bool> prime(1000001,1);
    prime[1] = 0;
    for(int i = 2;i <= 1000;i++){
        for(int j = 2;j*i<=1000000;j++){
            prime[i*j] = 0;
        }
    }
    for(int i = 0;i < N;i++){
        cin>>a;
        count = 0;
    for(int j = 2;j <= (a/2);j++){
        if(prime[j] == 1 && prime[a-j] == 1){
            count++;
        }
    }
    cout<<count<<endl;
    }
    return 0;
}