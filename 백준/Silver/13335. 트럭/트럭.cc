#include<iostream>
#include<queue>

using namespace std;

int main(void){
    int l,w,n,a,take = 0,result = 0;
    cin>>l>>w>>n;
    queue<int> bridge;
    for(int i = 0;i < l;i++){
        cin>>a;
        while(true){
            if(bridge.size() == w){
                take-=bridge.front();
                bridge.pop();
            }
            if(take+a <= n){
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