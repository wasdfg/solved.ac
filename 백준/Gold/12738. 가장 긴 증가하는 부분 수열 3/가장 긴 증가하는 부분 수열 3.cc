#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void){
    int n,num;
    cin>>n;
    vector<int> box(n,0);
    vector<int> lis;
    for(int i = 0;i < n;i++){
        cin>>box[i];
    }
    for(int i = 0;i < n;i++){
        if(lis.empty()){
            lis.push_back(box[i]);
        }
        else{
            if(lis.back() < box[i]){
                lis.push_back(box[i]);
            }
            else{
                auto it = lower_bound(lis.begin(),lis.end(),box[i]);
                *it = box[i];
            }
        }
    }
    cout<<lis.size();
    return 0;
}