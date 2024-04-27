#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void){
    int n,result = 0;
    cin>>n;
    vector<int> card(n,0);
    for(int i = 0;i < n;i++){
        cin>>card[i];
    }
    sort(card.begin(),card.end(),greater<int>());
    int level = max(card[0],card[1]);
    result+=card[0]+card[1];
    for(int i = 1;i < n-1;i++){
        level = max(level,card[i+1]);
        result+=(level+card[i+1]);
    }
    cout<<result;
    return 0;
}