#include<iostream>
#include<queue>

using namespace std;

int main(void){
    int n,count = 0,elec,me;
    cin>>n;
    priority_queue<int> pq;
    cin>>me;
    for(int i = 0;i < n-1;i++){
        cin>>elec;
        if(elec >= me){
            pq.push(elec);
        }
    }
    while(!pq.empty() && pq.top() >= me){
        int x = pq.top();
        pq.pop();
        x--;
        me++;
        count++;
        pq.push(x);
    }
    cout<<count;
    return 0;
}