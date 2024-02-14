#include<iostream>
#define ull unsigned long long

using namespace std;

int main(void){
    ull S,N = 0,num = 0,count = 0;
    cin>>S;
    for(ull i = 1;i <= S;i++){
        num+=i;
        if(num > S){
            break;
        }
        N++;
    }
    cout<<N;
    return 0;
}