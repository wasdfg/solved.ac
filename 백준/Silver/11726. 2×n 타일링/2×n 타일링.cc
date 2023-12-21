#include<iostream>
#include<vector>

using namespace std;

int main(void){
    int n;
    cin>>n;
    vector<unsigned long long> n2(n,0);
    n2[0] = 1;
    n2[1] = 2;
    for(int i = 2;i < n;i++){
        n2[i] = ((n2[i-1] % 10007) + (n2[i-2] % 10007)) % 10007;
    }
    cout<<n2[n-1];
    return 0;
}