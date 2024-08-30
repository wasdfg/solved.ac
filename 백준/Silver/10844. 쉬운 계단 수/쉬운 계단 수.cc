#include<iostream>
#include<vector>

using namespace std;

int main(void){
    long long n,result = 0;
    cin>>n;
    vector<vector<long long>> num(n,vector<long long>(10,0));
    for(int i = 1;i < 10;i++){
        num[0][i] = 1;
    }
    for(int i = 1;i < n;i++){
        for(int j = 0;j < 10;j++){
            if(j == 0){
                num[i][j] = num[i-1][j+1] % 1000000000 + num[i][j] % 1000000000;
            }
            else if(j == 9){
                num[i][j] = num[i-1][j-1] % 1000000000 + num[i][j] % 1000000000;
            }
            else{
                num[i][j] =num[i-1][j+1] % 1000000000 + num[i][j] % 1000000000 + num[i-1][j-1] % 1000000000;
            }
        }
    }
    for(int i = 0;i < 10;i++){
        result+=(num[n-1][i] % 1000000000);
    }
    cout<<result%1000000000;
    return 0;
}