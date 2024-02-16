#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int main(void){
    int N,M,cost,count = 0;
    vector<int> crane;
    vector<int> box;
    cin>>N;
    for(int i = 0;i < N;i++){
        cin>>cost;
        crane.push_back(cost);
    }
    cin>>M;
    for(int i = 0;i < M;i++){
        cin>>cost;
        box.push_back(cost);
    }
    sort(crane.begin(),crane.end());
    sort(box.begin(),box.end());
    if(box.back() > crane.back()){
        cout<<"-1\n";
    }
    else{
        while(!box.empty()){
            count++;
            for(int i = crane.size()-1;i >= 0;i--){
                for(int j = box.size()-1;j >= 0;j--){
                    if(crane[i] >= box[j]){
                        box.erase(box.begin()+j);
                        break;
                    }
                }
            }
        }
        cout<<count++;
    }
    
    return 0;
}