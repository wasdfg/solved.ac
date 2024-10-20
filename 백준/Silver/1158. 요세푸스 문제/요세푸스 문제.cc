#include<iostream>
#include<queue>

using namespace std;

int main(void){
    int n,k,count = 0;
    cin>>n>>k;
    queue<int> yose;
    for(int i = 1;i <= n;i++){
        yose.push(i);
    }
    cout<<"<";
    while(!yose.empty()){
        count++;
        int x = yose.front();
        if(count == k){
            if(yose.size() != 1){
                cout<<x<<", ";
            }
            else{
                cout<<x;
            }
            count = 0;
            yose.pop();
        }
        else{
            yose.pop();
            yose.push(x);
        }
    }
    cout<<">";
    return 0;
}