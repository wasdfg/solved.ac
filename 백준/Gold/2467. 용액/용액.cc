#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void){
    int n,start = 0,end,check = 2000000001,x,y;
    cin>>n;
    vector<int> liq(n,0);
    for(int i = 0;i < n;i++){
        cin>>liq[i];
    }
    sort(liq.begin(),liq.end());
    end = n-1;
    while(start < end){
        if(abs(liq[start]+liq[end]) <= check){
            check = abs(liq[start]+liq[end]);
            x = liq[start];
            y = liq[end];
        }
        if(liq[start]+liq[end] > 0){
            end--;
        }
        else{
            start++;
        }
    }
    cout<<x<<" "<<y;
    return 0;
}