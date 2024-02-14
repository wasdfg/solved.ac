#include<iostream>
#include<vector>
#include<algorithm>
#define ull unsigned long long

using namespace std;

int main(void){
    ull N,num,S = 0;
    cin>>N;
    vector<ull> A(N,0);
    vector<ull> B(N,0);
    for(int i = 0;i < N;i++){
        cin>>num;
        A[i] = num;
    }
    for(int i = 0;i < N;i++){
        cin>>num;
        B[i] = num;
    }
    sort(A.begin(),A.end());
    sort(B.begin(),B.end(),greater<ull>());
    for(int i = 0;i < N;i++){
        S += (A[i]*B[i]);
    }
    cout<<S;
    return 0;
}