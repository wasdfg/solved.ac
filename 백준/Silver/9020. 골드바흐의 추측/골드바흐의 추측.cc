#include<iostream>
#include<vector>

using namespace std;

int main(void){
    int n,t,high,low;
    cin>>t;
    vector<int> prime(10001,1);
    prime[0] = 0;
    prime[1] = 0;
    for(int j = 2;j <= 10000;j++){
        for(int k = 2;k*j <= 10000;k++){
            prime[j*k] = 0;
        }
    }
    for(int i = 0;i < t;i++){
        cin>>n;
        for(int j = n;j >= n/2;j--){
            if((prime[j] * prime[n-j]) == 1){
                high = j;
                low = n-j;
            }
        }
        cout<<low<<" "<<high<<endl;
    }
    return 0;
}