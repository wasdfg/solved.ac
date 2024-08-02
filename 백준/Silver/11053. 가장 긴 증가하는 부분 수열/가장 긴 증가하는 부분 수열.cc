#include<iostream>
#include<vector>

using namespace std;

int main(void){
    int n,num;
    cin>>n;
    vector<int> lcs;
    for(int i = 0;i < n;i++){
        cin>>num;
        if(lcs.empty() || lcs.back() < num){
            lcs.push_back(num);
        }
        else{
            int x = lower_bound(lcs.begin(),lcs.end(),num)-lcs.begin();
            lcs[x] = num;
        }
    }
    cout<<lcs.size();
    return 0;
}