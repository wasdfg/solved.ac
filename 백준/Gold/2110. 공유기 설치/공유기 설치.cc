#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void){
    int n,c,left,right,mid,check,result,setwifi;
    cin>>n>>c;
    vector<int> wifi(n,0);
    for(int i = 0;i < n;i++){
        cin>>wifi[i];
    }
    sort(wifi.begin(),wifi.end());
    left = 1;
    right = wifi.back();
    while(left <= right){
        mid = (left + right) / 2;
        check = 1;
        setwifi = wifi[0];
        for(int i = 1;i < n;i++){
            if(wifi[i] >= setwifi + mid){
                check++;
                setwifi = wifi[i];
            }
        }
        if(check >= c){
            result = mid;
            left = mid+1;
        }
        else{
            right = mid-1;
        }
    }
    cout<<result;
    return 0;
}