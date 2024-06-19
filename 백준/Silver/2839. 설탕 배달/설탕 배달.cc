#include<iostream>

using namespace std;

int main(void){
    int n,result = 1800,check;
    cin>>n;
    for(int i = n/5;i >= 0;i--){
        if((n-i*5)%3 == 0){
            result = min(result,i+(n-i*5)/3);
        }
    }
    if(result == 1800){
        cout<<"-1";
    }
    else{
        cout<<result;
    }
    return 0;
}