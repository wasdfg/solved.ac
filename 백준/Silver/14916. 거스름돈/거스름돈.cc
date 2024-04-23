#include<iostream>

using namespace std;

int main(void){
    int n,check,result = 50001,count = 0;
    cin>>n;
    for(int i = 0;i <= n/5;i++){
        check = n - 5*i;
        count = 0;
        if(check % 2 != 0){
            continue;
        }
        else{
            count+=i;
            count+=check/2;
            if(count < result){
                result = count;
            }
        }
    }
    if(result == 50001){
        cout<<"-1";
    }
    else{
        cout<<result;
    }
    return 0;
}