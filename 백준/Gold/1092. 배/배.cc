#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int main(void){
    int n,m,cost,count = 0,check = 0;
    vector<int> crane;
    vector<int> box;
    cin>>n;
    for(int i = 0;i < n;i++){
        cin>>cost;
        crane.push_back(cost);
    }
    cin>>m;
    for(int i = 0;i < m;i++){
        cin>>cost;
        box.push_back(cost);
    }
    sort(crane.begin(),crane.end(),greater<int>());
    sort(box.begin(),box.end(),greater<int>());
    if(box[0] > crane[0]){
        cout<<"-1\n";
    }
    else{
        while(1){
            int cranesize = 0;
            for(int i = 0;i < box.size();i++){
                if(cranesize >= crane.size()){
                    break;
                }
                if(box[i] != 0 && crane[cranesize] >= box[i]){
                    box[i] = 0;
                    check++;
                    cranesize++;
                }
            }
            count++;
            if(check == m){
                break;
            }
        }
        cout<<count;
    }
    return 0;
}