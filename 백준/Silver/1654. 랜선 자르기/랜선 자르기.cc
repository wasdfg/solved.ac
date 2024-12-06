#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void){
    long long n,k,left = 1,right,count,result = 0;
    cin>>k>>n;
    vector<long long> len(k,0);
    for(int i = 0;i < k;i++){
        cin>>len[i];
    }
    sort(len.begin(),len.end());
    right = len[k-1];
    while(left <= right){
        long long mid = (left + right)/2;
        count = 0;
        for(int i = 0;i < k;i++){
            count+=(len[i]/mid);
        }
        if(count >= n){
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