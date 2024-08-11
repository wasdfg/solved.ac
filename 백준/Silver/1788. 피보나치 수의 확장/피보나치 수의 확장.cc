#include<iostream>
#include<vector>

using namespace std;

vector<int> fibo(1000001,0);

int main(void){
    int n;
    cin>>n;
    fibo[1] = 1;
    for(int i = 2;i < 1000001;i++){
        fibo[i] = (fibo[i-1] % 1000000000 + fibo[i-2] % 1000000000) % 1000000000;
    }
    if(n < 0){
        if((n*-1) % 2 != 0){
            cout<<"1\n";
        }
        else{
            cout<<"-1\n";
        }
        cout<<(abs(fibo[n*-1]))%1000000000;
    }
    else if(n == 0){
        cout<<"0\n0\n";
    }
    else{
        cout<<"1\n"<<fibo[n]%1000000000;
    }
    return 0;
}