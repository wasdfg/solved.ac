#include<iostream>
#include<vector>

using namespace std;

int main(void){
    int n,k,count = 0;
    string a;
    cin>>n>>k;
    cin>>a;
    for(int i = 0;i < a.length();i++){
        if(a[i] == 'P'){
            for(int j = i-k; j <= i+k;j++) {
                if(0 <= j && j < n && a[j] == 'H') {
                    a[j]='-';
                    count++;
                    break;
                }
            }
        }
    }
    cout<<count;
    return 0;
}