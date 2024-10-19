#include<iostream>
#include<vector>

using namespace std;

int main(void){
    int n,k,left = 0,right = 0,count = 0,check;
    cin>>n>>k;
    vector<int> rion(n,0);
    for(int i = 0;i < n;i++){
        cin>>rion[i];
    }
    check = n+1;
    while(right < n){
        while(count < k && right < n){
            if(rion[right] == 1){
                count++;
            }
            right++;
        }
        while(count == k){
            check = min(right-left,check);
            if(rion[left] == 1){
                count--;
            }
            left++;
        }
    }
    if(check == n+1){
        cout<<"-1";
    }
    else{
        cout<<check;
    }
    return 0;
}