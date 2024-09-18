#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void){
    int n,num;
    cin>>n;
    vector<int> box;
    for(int i = 0;i < n;i++){
        cin>>num;
        if(box.empty() || box.back() > num){
            box.push_back(num);
        }
        else{
            int x = lower_bound(box.begin(),box.end(),num,greater<int>()) - box.begin();
            box[x] = num;
        }
    }
    cout<<box.size();
    return 0;
}