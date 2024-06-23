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
    ull a,b,c = 2,d = 1000000001;
    cin>>a>>b;
    for(int i = 1;i*i <= b/a;i++){
        if((b/a) % i == 0 && gcd((a*b)/(a*i),(a*i)) == a){
            if(d-c > ((a*b)/(a*i)-(a*i))){
                d = (a*b)/(a*i);
                c = a*i;
            }
        }
    }
    cout<<c<<" "<<d;
    return 0;
}