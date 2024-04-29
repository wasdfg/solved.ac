#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void){
    long long n,diff = 0;
    cin>>n;
    vector<long long> record(n,0);
    for(int i = 0;i < n;i++){
        cin>>record[i];
    }
    sort(record.begin(),record.end());
    for(int i = 0;i < n;i++){
        diff+=((i+1)-record[i]>0?(i+1)-record[i]:((i+1)-record[i])*-1);
    }
    cout<<diff;
    return 0;
}