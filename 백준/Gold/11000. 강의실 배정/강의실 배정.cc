#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

int main(void){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    long long n,s,t;
    priority_queue<long long,vector<long long>,greater<long long>> pq;
    cin>>n;
    vector<pair<int,int>> classroom;
    for(int i = 0;i < n;i++){
        cin>>s>>t;
        classroom.push_back({s,t});
    }
    sort(classroom.begin(),classroom.end());
    for(int i = 0;i < n;i++){
        if(pq.empty() || pq.top() > classroom[i].first){
            pq.push(classroom[i].second);
        }
        else{
            pq.pop();
            pq.push(classroom[i].second);
        }
    }
    cout<<pq.size();
    return 0;
}