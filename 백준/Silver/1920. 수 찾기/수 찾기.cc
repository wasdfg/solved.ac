#include<iostream>
#include<map>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n,x;
    cin>>n;
    map<long long,long long> a;
    for(long long i = 0;i < n;i++){
        cin>>x;
        a[x]++;
    }
    cin>>n;
    for(long long i = 0;i < n;i++){
        cin>>x;
        if(a[x] != 0){
            cout<<"1\n";
        }
        else{
            cout<<"0\n";
        }
    }
}