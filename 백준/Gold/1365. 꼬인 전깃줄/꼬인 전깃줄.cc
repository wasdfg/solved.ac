#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void){
    int n;
    cin>>n;
    vector<int> elc(n,0);
    vector<int> lis;
    for(int i = 0;i < n;i++){
        cin>>elc[i];
    }
    for(int i = 0;i < n;i++){
        if(lis.empty() || lis.back() < elc[i]){
            lis.push_back(elc[i]);
        }
        else{
            int x = lower_bound(lis.begin(),lis.end(),elc[i])-lis.begin();
            lis[x] = elc[i];
        }
    }
    cout<<n-lis.size();
    return 0;
}