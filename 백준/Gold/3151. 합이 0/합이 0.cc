#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void){
    int n,left,right;
    long long count = 0;
    cin>>n;
    vector<int> prog(n,0);
    for(int i = 0;i < n;i++){
        cin>>prog[i];
    }
    stable_sort(prog.begin(),prog.end());
    for(int i = 0;i < n-2;i++){
        for(int j = i+1;j < n-1;j++){
            left = lower_bound(prog.begin()+j+1,prog.end(),-prog[i]-prog[j])-prog.begin();
            right = upper_bound(prog.begin()+j+1,prog.end(),-prog[i]-prog[j])-prog.begin();
            count+=(right-left);
        }
    }
    cout<<count;
    return 0;
}