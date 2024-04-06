#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void){
    long long m,n,left,right,sum = 0,count,check = 0;
    cin>>m>>n;
    vector<long long> snack(n,0);
    for(int i = 0;i < n;i++){
        cin>>snack[i];
    }
    sort(snack.begin(),snack.end());
    left = 1;
    right = snack.back();
    while(left <= right){
        count = 0;
        long long mid = (left+right)/2;
        for(int i = 0;i < n;i++){
            count+=(snack[i]/mid);
        }
        if(count < m){
            right = mid-1;
        }
        else{
            check = mid;
            left = mid+1;
        }
    }
    cout<<check;
    return 0;
}