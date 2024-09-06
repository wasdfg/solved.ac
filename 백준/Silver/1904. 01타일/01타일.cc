#include<iostream>
#include<vector>

using namespace std;

int main(void){
    int n;
    cin>>n;
    vector<int> zo(n,0);
    zo[0] = 1;
    zo[1] = 2;
    for(int i = 2;i < n;i++){
        zo[i] = zo[i-1] % 15746 + zo[i-2] % 15746;
    }
    cout<<zo[n-1] % 15746;
    return 0;
}