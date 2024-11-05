#include<iostream>
#include<vector>
#define ull unsigned long long

using namespace std;

int main(void){
    ull s,k,result = 1;
    cin>>s>>k;
    vector<ull> num(k,s/k);
    s = s % k;
    for(int i = 0;i < num.size();i++){
        if(s == 0){
            break;
        }
        num[i]++;
        s--;
    }
    for(int i = 0;i < num.size();i++){
        result*=num[i];
    }
    cout<<result;
    return 0;
}