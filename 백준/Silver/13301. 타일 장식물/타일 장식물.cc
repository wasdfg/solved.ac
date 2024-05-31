#include<iostream>
#include<vector>

using namespace std;

int main(void){
    int n;
    cin>>n;
    if(n == 1){
        cout<<"4";
    }
    else if(n == 2){
        cout<<"6";
    }
    else{
        vector<long long> fibo(n+1,0);
        fibo[0] = 1;
        fibo[1] = 1;
        for(int i = 2;i < n+1;i++){
            fibo[i] = fibo[i-2]+fibo[i-1];
        }
        cout<<fibo[n]*2+fibo[n-1]*2;
    }
    return 0;
}