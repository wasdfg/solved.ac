#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

int main(void){
    int n,x;
    cin>>n;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    for(int i = 0;i < n;i++){
        cin>>x;
        if(x == 0){
            if(pq.empty()){
                cout<<"0\n";
            }
            else{
                cout<<pq.top().first*pq.top().second<<endl;
                pq.pop();
            }
        }
        else{
            pq.push({abs(x),x > 0?1:-1});
        }
    }
    return 0;
}