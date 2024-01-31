#include<iostream>
#include<vector>

using namespace std;

vector<int> fibo(2000001,0);

int main(void){
    int n;
    cin>>n;
    fibo[1000001] = 1;
    if(n < 0){
        for(int i = 1000001;i >= n+1000002;i--){
            fibo[i-2] = ((fibo[i] % 1000000000) - (fibo[i-1] % 1000000000)) % 1000000000;
        }
        if(fibo[n+1000000] > 0){
            cout<<"1\n";
        }
        else if(fibo[n+1000000] < 0){
            cout<<"-1\n";
        }
        else{
            cout<<"0\n";
        }
        cout<<abs(fibo[n+1000000]);
    }
    else{
        for(int i = 1000002;i <= n+1000000;i++){
            fibo[i] = ((fibo[i-1] % 1000000000) + (fibo[i-2] % 1000000000)) % 1000000000;
        }
        if(fibo[n+1000000] > 0){
            cout<<"1\n";
        }
        else if(fibo[n+1000000] < 0){
            cout<<"-1\n";
        }
        else{
            cout<<"0\n";
        }
        cout<<abs(fibo[n+1000000]);
    }
    return 0;
}