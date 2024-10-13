#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void){
    int n,h,x,count = 0,result = 200001;
    cin>>n>>h;
    vector<int> top(h+1,0);
    vector<int> bottom(h+1,0);
    for(int i = 0;i < n;i++){
        cin>>x;
        if(i % 2 == 0){
            bottom[x]++;
        }
        else{
            top[h-x+1]++;
        }
    }
    for(int i = 1;i <= h;i++){
        top[i]+=top[i-1];
        bottom[h-i]+=bottom[h-i+1];
    }
    for(int i = 1;i <= h;i++){
        if(top[i]+bottom[i] < result){
            count = 1;
            result = top[i]+bottom[i];
        }
        else if(top[i]+bottom[i] == result){
            count++;
        }
    }
    cout<<result<<" "<<count;
    return 0;
}