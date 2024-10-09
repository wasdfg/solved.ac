#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long t,n,m,num,answer = 0;
    vector<long long> asum,bsum;
    vector<long long> a,b;
    cin>>t>>n;
    for(int i = 0;i < n;i++){
        cin>>num;
        a.push_back(num);
    }
    cin>>m;
    for(int i = 0;i < m;i++){
        cin>>num;
        b.push_back(num);
    }
    for(int i = 0;i < n;i++){
        long long total = a[i];
        asum.push_back(total);
        for(int j = i+1;j < n;j++){
            total+=a[j];
            asum.push_back(total);
        }
    }
    for(int i = 0;i < m;i++){
        long long total = b[i];
        bsum.push_back(total);
        for(int j = i+1;j < m;j++){
            total+=b[j];
            bsum.push_back(total);
        }
    }
    sort(asum.begin(),asum.end());
    sort(bsum.begin(),bsum.end());
    for(int i = 0;i < asum.size();i++){
        long long check = t - asum[i];
        int x = upper_bound(bsum.begin(),bsum.end(),check) - bsum.begin();
        int y = lower_bound(bsum.begin(),bsum.end(),check) - bsum.begin();
        answer+=(x-y);
    }
    cout<<answer;
    return 0;
}