#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void){
    int n,check = 0;
    cin>>n;
    vector<int> num(n,0);
    vector<int> gdp(n,0);
    vector<int> ldp(n,0);
    for(int i = 0;i < n;i++){
        cin>>num[i];
    }
    for(int i = 0;i < n;i++){
        gdp[i] = 1;
        for(int j = 0;j < i;j++){
            if(num[i] > num[j]){
                gdp[i] = max(gdp[i],gdp[j]+1);
            }
        }
    }
    for(int i = n-1;i >= 0;i--){
        ldp[i] = 1;
        for(int j = n-1;j > i;j--){
            if(num[i] > num[j]){
                ldp[i] = max(ldp[i],ldp[j]+1);
            }
        }
    }
    for(int i = 0;i < n;i++){
        check = max(check,gdp[i]+ldp[i]);
    }
    cout<<check-1;
    return 0;
}