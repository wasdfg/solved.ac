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
    for(int i = 0;i < n-1;i++){
        for(int j = i+1;j < n;j++){
            int check = prog[i]+prog[j];
            int x = lower_bound(prog.begin()+j+1,prog.end(),-check) - prog.begin();
            int y = upper_bound(prog.begin()+j+1,prog.end(),-check) - prog.begin();
            count+=(y-x);
        }
    }
    cout<<count;
    return 0;
}