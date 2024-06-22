#include<iostream>
#include<vector>

using namespace std;

int main(void){
    int t,n;
    vector<int> one(41,0);
    vector<int> zero(41,0);
    cin>>t;
    zero[0] = 1;
    one[1] = 1;
    for(int i = 2;i < 41;i++){
        one[i] = one[i-1]+one[i-2];
        zero[i] = zero[i-1]+zero[i-2];
    }
    for(int i = 0;i < t;i++){
        cin>>n;
        cout<<zero[n]<<" "<<one[n]<<endl;
    }
    return 0;
}