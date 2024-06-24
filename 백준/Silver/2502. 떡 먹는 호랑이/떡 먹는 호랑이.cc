#include<iostream>
#include<vector>

using namespace std;

int main(void){
    int k,d;
    vector<int> a(31,0);
    vector<int> b(31,0);
    a[1] = 1;
    a[2] = 0;
    b[1] = 0;
    b[2] = 1;
    for(int i = 3;i < 31;i++){
        a[i] = a[i-1]+a[i-2];
        b[i] = b[i-1]+b[i-2];
    }
    cin>>d>>k;
    for(int i = 1;i*a[d] < k;i++){
        if((k-(a[d]*i)) % b[d] == 0){
            cout<<i<<endl;
            cout<<(k-a[d]*i) / b[d];
            return 0;
        }
    }
    return 0;
}