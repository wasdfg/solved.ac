#include<iostream>
#define ull unsigned long long

using namespace std;

ull a,b,c;

ull dnq(ull x){
    ull half = x/2;
    if(x == 1){
        return a%c;
    }
    else{
        ull y = dnq(half);
        if(x % 2 == 1){
            return (((y*y)%c)*(a%c))%c;
        }
        else{
            return (y*y)%c;
        }
    }
}

int main(void){    
    cin>>a>>b>>c;
    cout<<dnq(b)%c;
    return 0;
}