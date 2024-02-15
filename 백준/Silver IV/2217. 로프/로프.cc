#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void){
    int N,weight,result;
    vector<int> rope;
    cin>>N;
    for(int i = 0;i < N;i++){
        cin>>weight;
        rope.push_back(weight);
    }
    sort(rope.begin(),rope.end(),greater<int>());
    result = rope[0];
    for(int i = 1;i < N;i++){
        result = max(min(rope[i],rope[i-1]) * (i+1),result);
    }
    cout<<result;
    return 0;
}