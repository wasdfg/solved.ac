#include<iostream>
#include<vector>

using namespace std;

int main(void){
    int t,n;
    vector<bool> prime(250000,1);
    prime[1] = 0;
    for(int i = 2;i*i <= 250000;i++){
        for(int j = 2;j*i <= 250000;j++){
            prime[i*j] = 0;
        }
    }
    while(1){
        cin>>n;
        if(n == 0){
            return 0;
        }
        int count = 0;
        for(int j = n+1;j <= 2*n;j++){
            if(prime[j] == 1){
                count++;
            }
        }
        cout<<count<<endl;
    }
    return 0;
}