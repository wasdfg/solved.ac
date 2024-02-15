#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

int main(void){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    long long N,s,t;
    vector<pair<long long,long long>> tclass; 
    priority_queue<long long,vector<long long>,greater<long long>> room;
    cin>>N;
    for(int i = 0;i < N;i++){
        cin>>s>>t;
        tclass.push_back({s,t});
    }
    sort(tclass.begin(),tclass.end());
    room.push(tclass[0].second);
    for(int i = 1;i < N;i++){
        if(tclass[i].first >= room.top()){
            room.pop();
            room.push(tclass[i].second);
        }
        else{
            room.push(tclass[i].second);
        }
    }
    cout<<room.size();
    return 0;
}