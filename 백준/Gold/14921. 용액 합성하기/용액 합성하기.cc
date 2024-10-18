#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void){
    int n,left,right,result = 200000001;
    cin>>n;
    vector<int> liq(n,0);
    for(int i = 0;i < n;i++){
        cin>>liq[i];
    }
    sort(liq.begin(),liq.end());
    left = 0,right = n-1;
    while(left < right){
        if(liq[left]+liq[right] == 0){
            result = 0;
            break;
        }
        else if(liq[left]+liq[right] > 0){
            if(abs(result) > abs(liq[left]+liq[right])){
                result = liq[left]+liq[right];
            }
            right--;
        }
        else{
            if(abs(result) > abs(liq[left]+liq[right])){
                result = liq[left]+liq[right];
            }
            left++;
        }
    }
    cout<<result;
    return 0;
}