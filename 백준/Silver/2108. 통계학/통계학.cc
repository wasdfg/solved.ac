#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>

using namespace std;

bool cmp(const pair<int,int>& a, const pair<int,int>& b) {
	if (a.second == b.second) return a.first < b.first;
	return a.second > b.second;
}

int main(void){
    int n,a,cen,rng,less;
    double avg = 0;
    vector<int> num;
    map<int,int> count;
    cin>>n;
    for(int i = 0;i < n;i++){
        cin>>a;
        num.push_back(a);
        count[a]++;
    }
    vector<pair<int,int>> tmp(count.begin(),count.end());
    stable_sort(num.begin(),num.end());
    sort(tmp.begin(),tmp.end(),cmp);
    for(int i = 0;i < num.size();i++){
        avg+=num[i];
    }
    avg/=num.size();
    avg = round(avg);
    if(avg == 0){
        avg = 0;
    }
    if(n % 2 == 0){
        cen = num[n/2-1];
    }
    else{
        cen = num[n/2];
    }
    if(n > 1){
        if(tmp[0].second == tmp[1].second){
            less = tmp[1].first;
        }
        else{
            less = tmp[0].first;
        }
    }
    else{
        less = tmp.front().first;
    }
    rng = num.back() - num.front();
    cout<<avg<<endl<<cen<<endl<<less<<endl<<rng;
    return 0;
}
