#include<iostream>
#include<vector>
#include<algorithm>
#define ull unsigned long long

using namespace std;

int main(void){
    ull n,m,left,right,result = 0;
    cin>>n>>m;
    vector<ull> cp(n,0);
    for(int i = 0;i < n;i++){
        cin>>cp[i];
    }
    sort(cp.begin(),cp.end());
    left = 1;
    right = m*cp[n-1];
    while(left <= right){
        ull mid = (left+right)/2;
        ull check = 0;
        for(int i = 0;i < n;i++){
            check+=(mid/cp[i]);
        }
        if(check >= m){
            right = mid-1;
            result = mid;
        }
        else{
            left = mid+1;
        }
    }
    cout<<result;
    return 0;
}