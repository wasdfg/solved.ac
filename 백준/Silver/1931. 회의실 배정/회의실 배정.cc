#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool cmp(pair<long long,long long>&a,pair<long long,long long>&b){
    if(a.second == b.second){
        return a.first < b.first;
    }
    else{
        return a.second < b.second;
    }
}

int main(void){
    long long n,a,b,result = 0,fin = 0;
    cin>>n;
    vector<pair<long long,long long>> room;
    for(int i = 0;i < n;i++){
        cin>>a>>b;
        room.push_back({a,b});
    }
    sort(room.begin(),room.end(),cmp);
    for(int i = 0;i < n;i++){
        if(fin <= room[i].first){
            result++;
            fin = room[i].second;
        }
    }
    cout<<result;
    return 0;
}