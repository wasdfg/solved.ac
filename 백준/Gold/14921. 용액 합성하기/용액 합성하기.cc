#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int main(void){
    int n,check = 200000001,left,right,l,r;
    cin>>n;
    vector<int> liq(n,0);
    for(int i = 0;i < n;i++){
        cin>>liq[i];
    }
    left = 0;
    right = n-1;
    while(left < right){
        if(abs(liq[left]+liq[right]) < check){
            check = abs(liq[left]+liq[right]);
            l = left;
            r = right;
        }
        if(liq[left]+liq[right] > 0){
            right--;
        }
        else{
            left++;
        }
    }
    cout<<liq[l]+liq[r];
    return 0;
}