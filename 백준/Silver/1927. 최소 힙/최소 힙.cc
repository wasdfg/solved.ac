#include<iostream>
#include<queue>

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,x;
    priority_queue<int,vector<int>,greater<int>> pq;
    cin>>n;
    for(int i = 0;i < n;i++){
        cin>>x;
        if(x == 0){
            if(pq.empty()){
                cout<<"0\n";
            }
            else{
                cout<<pq.top()<<"\n";
                pq.pop();
            }
        }
        else{
            pq.push(x);
        }
    }
    return 0;
}