#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void){
    int l,r = 0,mid,n,m;
    cin>>n>>m;
    vector<int> guitar(n,0);
    for(int i = 0;i < n;i++){
        cin>>guitar[i];
        r+=guitar[i];
    }
    l = *max_element(guitar.begin(),guitar.end());
    while(l <= r){
        mid = (l+r)/2;
        int total = 0,check = 0;
        for(int i = 0;i < n;i++){
            if(total+guitar[i] > mid){
                total = 0;
                check++;
            }
            total+=guitar[i];
        }
        if(total != 0){
            check++;
        }
        if(check > m){
            l = mid+1;
        }
        else{
            r = mid-1;
        }
    }
    cout<<l;
    return 0;
}