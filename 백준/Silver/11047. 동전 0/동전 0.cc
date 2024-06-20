#include<iostream>
#include<vector>

using namespace std;

int main(void){
    int n,k,cost,result = 0;
    vector<int> money;
    cin>>n>>k;
    for(int i = 0;i <n;i++){
        cin>>cost;
        if(cost <= k){
            money.push_back(cost);
        }
    }
    for(int i = money.size()-1;i >= 0;i--){
        if(k == 0){
            break;
        }
        result+=(k/money[i]);
        k=(k%money[i]);
    }
    cout<<result;
    return 0;
}