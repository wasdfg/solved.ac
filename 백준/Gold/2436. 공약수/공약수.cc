#include<iostream>
#define ull unsigned long long

using namespace std;

ull gcd(ull x,ull y){
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
    ull a,b,c = 2,d = 100000001;
    cin>>a>>b;
    for(int i = 1;i*i <= b/a;i++){
        if((b/a) % i == 0){
            if(gcd(b/a/i,i) == 1 &&  i + b/a/i < c+d){
                c = i;
                d = b/a/i;
            }
        }
    }
    cout<<c*a<<" "<<d*a;
    return 0;
}