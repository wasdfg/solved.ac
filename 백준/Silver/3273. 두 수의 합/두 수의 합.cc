#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void){
    int start = 0,end,n,x,count = 0;
    cin>>n;
    end = n-1;
    vector<int> num(n,0);
    for(int i = 0;i < n;i++){
        cin>>num[i];
    }
    sort(num.begin(),num.end());
    cin>>x;
    while(start < end){
        if(num[start]+num[end] == x){
            count++;
            start++;
            end--;
        }
        else if(num[start]+num[end] > x){
            end--;
        }
        else{
            start++;
        }
    }
    if(n == 1){
        cout<<"0";
    }
    else{
        cout<<count;
    }
    return 0;
}