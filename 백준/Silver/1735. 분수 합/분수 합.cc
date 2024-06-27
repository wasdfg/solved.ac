#include<iostream>

using namespace std;

long gcd(long x,long y){
    if(x < y){
        swap(x,y);
    }
    if(y == 0){
        return x;
    }
    else{
        return gcd(y,x%y);
    }
}

int main(void){
    long a,b,c,d;
    cin>>a>>b>>c>>d;
    long x = gcd(b,d);
    long y = b*d/x;
    long i = a*y/b+c*y/d;
    long t = gcd(i,y);
    cout<<i/t<<" "<<y/t;
    return 0;
}