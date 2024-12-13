#include<iostream>
#include<vector>

using namespace std;

int main(void){
    int n,k,result = -10000001,check = 0;
    cin>>n>>k;
    vector<int> degree(n,0);
    for(int i = 0;i < n;i++){
        cin>>degree[i];
    }
    for(int i = 0;i < k;i++){
        check+=degree[i];
    }
    result = check;
    for(int i = 0;i < n-k;i++){
        check-=degree[i];
        check+=degree[k+i];
        result = max(check,result);
    }
    cout<<result;
    return 0;
}