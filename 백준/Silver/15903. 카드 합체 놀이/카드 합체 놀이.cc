#include<iostream>
#include<queue>

using namespace std;

int main(void){
    int n,m;
    long long a,check,result;
    priority_queue<long long,vector<long long>,greater<long long>> pq;
    cin>>n>>m;
    for(int i = 0;i < n;i++){
        cin>>a;
        pq.push(a);
    }
    while(m > 0){
        result = 0;
        check = pq.top();
        pq.pop();
        result+= (check + pq.top());
        pq.pop();
        pq.push(result);
        pq.push(result);
        m--;
    }
    result = 0;
    while(!pq.empty()){
        result+=pq.top();
        pq.pop();
    }
    cout<<result;
    return 0;
}