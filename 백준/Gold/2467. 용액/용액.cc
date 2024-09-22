#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void){
    int n,start = 0,last,check = 2000000001,x,y;
    cin>>n;
    vector<int> liq(n,0);
    for(int i = 0;i < n;i++){
        cin>>liq[i];
    }
    last = n-1;
    sort(liq.begin(),liq.end());
    while(start < last){
        if(abs(liq[start]+liq[last]) <= check){
            check = abs(liq[start]+liq[last]);
            x = min(liq[start],liq[last]);
            y = max(liq[start],liq[last]);
        }
        if(liq[start]+liq[last] < 0){
            start++;
        }
        else{
            last--;
        }
    }
    cout<<x<<" "<<y;
    return 0;
}