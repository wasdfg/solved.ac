#include<iostream>
#include<queue>

using namespace std;

int main(void){
    int l,w,n,a,take = 0,result = 0;
    cin>>n>>w>>l;
    queue<int> bridge;
    for(int i = 0;i < n;i++){
        cin>>a;
        while(1){
            if(bridge.size() == w){
                take-=bridge.front();
                bridge.pop();
            }
            if(take+a <= l){
                break;
            }
            bridge.push(0);
            result++;
        }
        bridge.push(a);
        take+=a;
        result++;
    }
    cout<<result+w;
    return 0;
}