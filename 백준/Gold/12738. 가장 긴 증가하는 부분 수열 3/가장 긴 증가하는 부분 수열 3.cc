#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void){
    int n,num;
    vector<int> lis;
    cin>>n;
    for(int i = 0;i < n;i++){
        cin>>num;
        if(lis.empty() || lis.back() < num){
            lis.push_back(num);
        }
        else{
            int x = lower_bound(lis.begin(),lis.end(),num)-lis.begin();
            lis[x] = num;
        }
    }
    cout<<lis.size();
    return 0;
}