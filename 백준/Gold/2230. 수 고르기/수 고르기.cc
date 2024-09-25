#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void){
    int start = 0,end = 0,check = 2000000001,n,m;
    cin>>n>>m;
    vector<int> choose(n,0);
    for(int i = 0;i < n;i++){
        cin>>choose[i];
    }
    sort(choose.begin(),choose.end());
    while(start <= end && end < n){
        if(choose[end] - choose[start] >= m){
            if(check >= choose[end] - choose[start]){
                check = choose[end] - choose[start];
            }
        }
        if(choose[end] - choose[start] >= m){
            start++;
        }
        else{
            end++;
        }
    }
    cout<<check;
    return 0;
}