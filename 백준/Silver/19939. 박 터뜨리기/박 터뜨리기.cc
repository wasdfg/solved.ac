#include<iostream>
#include<vector>

using namespace std;

int main(void){
    int n,k,sum;
    cin>>n>>k;
    sum = (k*(k+1))/2;
    if(sum > n){
        cout<<"-1";
    }
    else{
        if((n-sum)%k != 0){
            cout<<k;
        }
        else{
            cout<<k-1;
        }
    }
    return 0;
}