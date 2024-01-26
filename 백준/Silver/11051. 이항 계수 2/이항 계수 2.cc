#include<iostream>
#include<vector>
typedef unsigned long long ull;
using namespace std;


int main(void){
    int n,k;
    cin>>n>>k;
    vector<vector<ull>> c(n+1,vector<ull>(n+1,0));
    for(int i = 0;i <= n;i++){
        for(int j = 0;j <= i;j++){
            if(i == j || j == 0){
                c[i][j] = 1;
            }
            else{
                c[i][j] = ((c[i-1][j] % 10007) + (c[i-1][j-1] % 10007)) % 10007;
            }
        }
    }
    cout<<c[n][k];
    return 0;
}