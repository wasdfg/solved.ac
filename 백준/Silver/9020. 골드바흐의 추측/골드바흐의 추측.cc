#include<iostream>
#include<vector>

using namespace std;

int main(void){
    int n,t,high,low;
    cin>>t;
    vector<int> prime(10001,1);
    prime[0] = 0;
    prime[1] = 0;
    for(int i = 2;i < 10001;i++){
        for(int j = 2;j * i < 10001;j++){
            prime[i*j] = 0;
        }
    }
    for(int i = 0;i < t;i++){
        cin>>n;
        for(int i = 2;i < (n+1)/2+1;i++){
            if(prime[i]*prime[n-i] == 1){
                high = n-i;
                low = i;
            }
        }
        cout<<low<<" "<<high<<"\n";
    }
    return 0;
}