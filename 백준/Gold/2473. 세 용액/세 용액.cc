#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void){
    long long n,left,right,a,b,c,check = 3000000001;
    cin>>n;
    vector<long long> liq(n,0);
    for(int i = 0;i < n;i++){
        cin>>liq[i];
    }
    sort(liq.begin(),liq.end());
    for(int i = 0;i < n-2;i++){
        left = i+1;
        right = n-1;
        while(left < right){
            if(abs(liq[i]+liq[left]+liq[right]) < check){
                a = liq[i];
                b = liq[left];
                c = liq[right];
                check = abs(liq[i]+liq[left]+liq[right]);
            }
            if(liq[i]+liq[left]+liq[right] > 0){
                right--;
            }
            else{
                left++;
            }
        }
    }
    cout<<a<<" "<<b<<" "<<c;
    return 0;
}