#include<iostream>
#include<algorithm>
#include<vector>
typedef unsigned long long ull;
using namespace std;

vector<pair<ull,ull>> time;

bool compare(const pair<ull, ull>&a, const pair<ull, ull>&b){
    if(a.second == b.second)
        return a.first < b.first;
	return a.second < b.second;
}

int main(void){
    int n,count = 1;
    ull start,end;
    cin>>n;
    for(int i = 0;i < n;i++){
        cin>>start>>end;
        time.push_back(make_pair(start,end));
    }
    stable_sort(time.begin(),time.end(),compare);

    ull next = time[0].second;
    for(int i = 1;i < n;i++){
        if(next > time[i].first)
            continue;
        else{
            next = time[i].second;
            count++;
        }
    }
    cout<<count<<endl;
}