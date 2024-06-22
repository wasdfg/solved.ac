#include<iostream>
#include<vector>

using namespace std;

int main(void){
    int n,m;
    vector<int> prime(1000001,1);
    prime[1] = 0;
    cin>>n>>m;
    for(int i = 2;i*i <= 1000000;i++){
        for(int j = 2;j*i <= 1000000;j++){
            prime[i*j] = 0;
        }
    }
    for(int i = n;i <= m;i++){
        if(prime[i] == 1){
            cout<<i<<"\n";
        }
    }
    return 0;
}