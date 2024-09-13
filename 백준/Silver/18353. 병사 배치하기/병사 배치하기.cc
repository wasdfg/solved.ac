#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void){
    int n,m;
    cin>>n;
    vector<int> sol;
    for(int i = 0;i < n;i++){
        cin>>m;
        if(sol.empty() || sol.back() > m){
            sol.push_back(m);
        }
        else{
            int tmp = upper_bound(sol.begin(),sol.end(),m,greater<int>())-sol.begin();
            sol[tmp] = m;
        }
    }
    cout<<n-sol.size();
    return 0;
}