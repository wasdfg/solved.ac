#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void){
    int T,N,a,b,peer;
    vector<pair<int,int>> order;
    cin>>T;
    for(int i = 0;i < T;i++){
        order.clear();
        cin>>N;
        peer = 0;
        for(int j = 0;j < N;j++){
            cin>>a>>b;
            order.push_back({a,b});
        }
        sort(order.begin(),order.end());
        int mini = 1000001;
        for(int j = 0;j < N;j++){
            if(mini > order[j].second){
                peer++;
                mini = order[j].second;
            }
        }
        cout<<peer<<endl;
    }
    return 0;
}