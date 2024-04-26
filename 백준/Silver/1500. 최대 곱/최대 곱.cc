#include<iostream>
#include<vector>
#define ull unsigned long long

using namespace std;

int main(void){
    ull s,k,result = 1,rest,count = 0;
    cin>>s>>k;
    vector<ull> num(k,s/k);
    rest = s-s/k*k;
    for(int i = 0;i < s/k*k;i++){
        if(count == rest){
            break;
        }
        num[i]++;
        count++;
    }
    for(int i = 0;i < k;i++){
        result*=num[i];
    }
    cout<<result;
    return 0;
}