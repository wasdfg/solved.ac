#include<iostream>

using namespace std;

long long gcd(long long a,long long b){
    if(a < b){
        swap(a,b);
    }
    if(b == 0){
        return a;
    }
    else{
        return gcd(b,a%b);
    }
}

int main(void){
    long long n,a,b;
    cin>>n;
    for(long long i = 0;i < n;i++){
        cin>>a>>b;
        long long x = gcd(a,b);
        cout<<a*b/x<<endl;
    }
    return 0;
}