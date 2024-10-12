#include<iostream>
#include<stack>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,a;
    cin>>n;
    stack<pair<int,int>> tower;
    for(int i = 0;i < n;i++){
        cin>>a;
        while(!tower.empty()){
            if(a < tower.top().first){
                cout<<tower.top().second<<" ";
                break;
            }
            tower.pop();
        }
        if(tower.empty()){
            cout<<"0"<<" ";
        }
        tower.push({a,i+1});
    }
    return 0;
}