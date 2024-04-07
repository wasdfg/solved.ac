#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void){
    unsigned long long n,m,left,right,count,result = 1e+19;
    cin>>n>>m;
    vector<unsigned long long> ent(n,0);
    for(int i = 0;i < n;i++){
        cin>>ent[i];
    }
    sort(ent.begin(),ent.end());
    left = 1;
    right = ent.back()*m;
    while(left <= right){
        count = 0;
        unsigned long long mid = (left+right)/2;
        for(int i = 0;i < n;i++){
            count+=(mid/ent[i]);
        }
        if(count >= m){
            right = mid-1;
            result = min(mid,result);
        }
        else{
            left = mid+1;
        }
    }
    cout<<result;
    return 0;
}