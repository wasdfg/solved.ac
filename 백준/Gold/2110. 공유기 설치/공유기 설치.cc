#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void){
    int n,c,left,right,check,result = 0,gap;
    cin>>n>>c;
    vector<int> wifi(n,0);
    for(int i = 0;i < n;i++){
        cin>>wifi[i];
    }
    sort(wifi.begin(),wifi.end());
    left = 1;
    right = wifi[n-1]-wifi[0];
    while(left <= right){
        check = 1;
        gap = wifi[0];
        int mid = (left+right)/2;
        for(int i = 0;i < n;i++){
            if(wifi[i] - gap >= mid){
                check++;
                gap = wifi[i];
            }
        }
        if(check >= c){
            result = max(result,mid);
            left = mid+1;
        }
        else{
            right = mid-1;
        }
    }
    cout<<result;
    return 0;
}