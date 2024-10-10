#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void){
    long long n,count = 0;
    cin>>n;
    vector<long long> a,b;
    vector<vector<long long>> array(n,vector<long long>(4,0));
    for(int i = 0;i < n;i++){
        cin>>array[i][0]>>array[i][1]>>array[i][2]>>array[i][3];
    }
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            a.push_back(array[i][0]+array[j][1]);
            b.push_back(array[i][2]+array[j][3]);
        }
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    for(int i = 0;i < a.size();i++){
        long long x = upper_bound(b.begin(),b.end(),-a[i]) - b.begin();
        long long y = lower_bound(b.begin(),b.end(),-a[i]) - b.begin();
        count+=(x-y);
    }
    cout<<count;
    return 0;
}