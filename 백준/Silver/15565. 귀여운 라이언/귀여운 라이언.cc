#include<iostream>
#include<vector>

using namespace std;

int main(void){
    int n,k,x,count = 0,left = 0,right,len;
    cin>>n>>k;
    vector<int> rion;
    for(int i = 0;i < n;i++){
        cin>>x;
        if(x == 1){
            rion.push_back(i+1);
        }
    }
    if(rion.size() < k){
        cout<<"-1";
        return 0;
    }
    len = n+1;
    right = k-1;
    for(int i = 0;i <= rion.size()-k;i++){
        len = min(len,rion[right]-rion[left]+1);
        right++;
        left++;
    }
    cout<<len;
    return 0;
}