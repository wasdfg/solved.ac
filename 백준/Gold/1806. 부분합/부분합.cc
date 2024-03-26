#include<iostream>
#include<vector>

using namespace std;

int main(void){
    int start = 0,end = 0,n,s,check = 100000,result;
    cin>>n>>s;
    vector<int> nsum(n,0);
    for(int i = 0;i < n;i++){
        cin>>nsum[i];
    }
    result = nsum[0];
    while(start <= end && end < n){
        if(result >= s){
            if(check > end-start+1){
                check = end-start+1;
            }
        }
        if(result < s){
            end++;
            result+=nsum[end];
        }
        else{
            result-=nsum[start];
            start++;
        }
    }
    if(check != 100000){
        cout<<check;
    }
    else{
        cout<<0;
    }
    return 0;
}