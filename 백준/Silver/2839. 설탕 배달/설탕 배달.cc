#include<iostream>

using namespace std;

int main(void){
    int n,result = 1800,check;
    cin>>n;
    for(int i = 0;i <= n/5;i++){
        for(int j = 0;j <= n/3;j++){
            if(i*5+j*3 == n){
                result = min(result,i+j);
            }
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