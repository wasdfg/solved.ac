#include<iostream>
#include<vector>

using namespace std;

int main(void){
    long long t,n;
    cin>>t;
    for(int i = 0;i < t;i++){
        cin>>n;
        vector<long long> stock(n,0);
        for(int j = 0;j < n;j++){
            cin>>stock[j];
        }
        long long result = 0;
        long long check = stock[n-1];
        for(int j = n-1;j >= 0;j--){
            if(check < stock[j]){
                check = stock[j];
            }
            else{
                result+=(check-stock[j]);
            }
        }
        cout<<result<<endl;
    }
    return 0;
}