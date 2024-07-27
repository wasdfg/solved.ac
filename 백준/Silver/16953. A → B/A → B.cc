#include<iostream>
#include<queue>
#include<map>

using namespace std;

int main(void){
    long long a,b;
    cin>>a>>b;
    queue<long long> togo;
    map<long long,long long> check;
    togo.push(a);
    while(!togo.empty()){
        long long now = togo.front();
        togo.pop();
        if(now == b){
            break;
        }
        if(now*10+1 <= b){
            togo.push(now*10+1);
            check[now*10+1] = check[now]+1;
        }
        if(now*2 <= b){
            togo.push(now*2);
            check[now*2] = check[now]+1;
        }
    }
    if(check[b] == 0){
        cout<<"-1";
    }
    else{
        cout<<check[b]+1;
    }
    return 0;
}
