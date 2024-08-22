#include<iostream>
#include<vector>

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    vector<bool> prime(1000001,1);
    prime[0] = 0;
    prime[1] = 0;
    for(int i = 2;i < 1000001;i++){
        for(int j = 2;i*j < 1000001;j++){
            prime[i*j] = 0;
        }
    }
    while(1){
        bool notprime = false;
        cin>>n;
        if(n == 0){
            break;
        }
        else{
            for(int i = 2;i < n;i++){
                if(prime[i] == 1 && prime[n-i] == 1){
                    notprime = true;
                    cout<<n<<" = "<<i<<" + "<<n-i<<"\n";
                    break;
                }
            }
            if(notprime == false){
                cout<<"Goldbach's conjecture is wrong.\n";
            }
        }
    }
    
    return 0;
}