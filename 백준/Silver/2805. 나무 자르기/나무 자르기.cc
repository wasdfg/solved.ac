#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void){
    long long n,m,left = 1,right,count,result = 0;
    cin>>n>>m;
    vector<long long> tree(n,0);
    for(int i = 0;i < n;i++){
        cin>>tree[i];
    }
    sort(tree.begin(),tree.end());
    right = tree[n-1];
    while(left <= right){
        long long mid = (left + right)/2;
        count = 0;
        for(int i = 0;i < n;i++){
            count+=(tree[i]-mid > 0?tree[i]-mid:0);
        }
        if(count >= m){
            result = max(mid,result);
            left = mid+1;
        }
        else{
            right = mid-1;
        }
    }
    cout<<result;
    return 0;
}