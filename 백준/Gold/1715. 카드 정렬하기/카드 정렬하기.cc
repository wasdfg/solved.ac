#include<iostream>
#include<queue>

using namespace std;

int main(void){
    long long n,quantity,result = 0;
    cin>>n;
    priority_queue<long long,vector<long long>,greater<int>> card;
    for(int i = 0;i < n;i++){
        cin>>quantity;
        card.push(quantity);
    }
    while(card.size() != 1){
        long long a = card.top();
        card.pop();
        long long b = card.top();
        card.pop();
        card.push(a+b);
        result+=(a+b);
    }
    cout<<result;
    return 0;
}