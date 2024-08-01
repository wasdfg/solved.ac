#include<iostream>
#include<queue>

using namespace std;

int main(void){
    int n,m;
    long long num,result = 0;
    cin>>n>>m;
    priority_queue<long long,vector<long long>,greater<long long>> card;
    for(int i = 0;i < n;i++){
        cin>>num;
        card.push(num);
    }
    for(int i = 0;i < m;i++){
        long long x = card.top();
        card.pop();
        long long y = card.top();
        card.pop();
        long long tmp = x;
        x+=y;
        y+=tmp;
        card.push(x);
        card.push(y);
    }
    while(!card.empty()){
        result+=card.top();
        card.pop();
    }
    cout<<result;
    return 0;
}