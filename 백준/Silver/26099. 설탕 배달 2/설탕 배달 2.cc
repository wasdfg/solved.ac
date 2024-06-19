#include<iostream>

using namespace std;

int main(void){
    long long n,result = 0;
    cin>>n;
    while(n >= 0){
        if(n % 5 == 0){
            result+=(n/5);
            cout<<result;
            return 0;
        }
        n-=3;
        result++;
    }
    cout<<-1;
    return 0;
}