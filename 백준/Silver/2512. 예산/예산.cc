#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void){
    int n,m,result = 0,check,start = 0,end;
    cin>>n;
    vector<int> money(n,0);
    for(int i = 0;i < n;i++){
        cin>>money[i];
    }
    cin>>m;
    sort(money.begin(),money.end());
    end = money[n-1];
    while(start <= end){
        check = 0;
        int mid = (end + start)/2;
        for(int i = 0;i < n;i++){
            check+=min(mid,money[i]);
        }
        if(check <= m){
            result = mid;
            start = mid+1; 
        }
        else{
            end = mid-1;
        }
    }
    cout<<result;
    return 0;
}