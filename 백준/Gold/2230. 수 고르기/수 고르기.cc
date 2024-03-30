#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void){
    int start,end,check,n,m;
    cin>>n>>m;
    vector<int> choose(n,0);
    for(int i = 0;i < n;i++){
        cin>>choose[i];
    }
    sort(choose.begin(),choose.end());
    start = 0,end = 0;
    check = 2000000001;
    while(end < n){
        if(choose[end] - choose[start] >= m){
            check = min(check, choose[end] - choose[start]);
            if(check == m){
                break;
            }
            start++;
        }
        else{
            end++;
        }
    }
    if(n == 1){
        cout<<choose.front();
    }
    else{
        cout<<check;
    }
    return 0;
}