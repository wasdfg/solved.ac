#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void){
    int n,a;
    cin>>n;
    vector<int> lcs;
    for(int i = 0;i < n;i++){
        cin>>a;
        if(lcs.empty() || lcs.back() < a){
            lcs.push_back(a);
        }
        else{
            int x = lower_bound(lcs.begin(),lcs.end(),a)-lcs.begin();
            lcs[x] = a;
        }
    }
    cout<<lcs.size();
    return 0;
}