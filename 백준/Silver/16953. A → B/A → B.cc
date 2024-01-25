#include<iostream>
#include<map>
#include<queue>

using namespace std;

map<long long,long long> num;

int main(void){
    long long A,B;
    cin>>A>>B;
    queue<long long> togo;
    togo.push(A);
    num[A] = 1;
    while(!togo.empty()){
        long long x = togo.front();
        togo.pop();
        if(x == B){
            break;
        }
        if((x*10+1) <= B){
            num[x*10+1]= num[x]+1;
            togo.push(x*10+1);
        }
        if(x*2 <= B){
            num[x*2] = num[x]+1;
            togo.push(x*2);
        }
    }
    if(num[B] != 0){
        cout<<num[B];
    }
    else{
        cout<<"-1";
    }
    return 0;
}
