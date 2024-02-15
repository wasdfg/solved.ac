#include<iostream>
#include<queue>

using namespace std;

int main(void){
    long long N,amount,result = 0;
    priority_queue<long long,vector<long long>,greater<long long>> card;
    cin>>N;
    for(int i = 0;i < N;i++){
        cin>>amount;
        card.push(amount);
    }
    while(card.size() != 1){
        long long a = card.top();
        card.pop();
        long long b = card.top();
        card.pop();
        card.push(a+b);
        result += a + b;
    }
    cout<<result;
    return 0;
}