#include<iostream>
#include<vector>

using namespace std;

int main(void){
    int n,m,left = 1,right,mid,count,check,result = 0;
    cin>>n>>m;
    vector<int> guitar(n,0);
    for(int i = 0;i < n;i++){
        cin>>guitar[i];
        result+=guitar[i];
        left = max(guitar[i],left);
    }
    right = result;
    while(left <= right){
        mid = (left+right)/2;
        count = 0;
        check = 0;
        for(int i = 0;i < n;i++){
            if(check+guitar[i] > mid){
                count++;
                check = 0;
            }
            check+=guitar[i];
        }
        if(check > 0){
            count++;
        }
        if(count <= m){
            right = mid-1; 
        }
        else{
            left = mid+1;
        }
    }
    cout<<left;
    return 0;
}