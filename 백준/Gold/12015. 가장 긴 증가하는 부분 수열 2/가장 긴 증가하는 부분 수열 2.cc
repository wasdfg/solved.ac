#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void){
    int n;
    cin>>n;
    vector<int> lis;
    vector<int> num(n,0);
    for(int i = 0;i < n;i++){
        cin>>num[i];
    }
    for(int i = 0;i < n;i++){
        if(lis.empty() || lis.back() < num[i]){
            lis.push_back(num[i]);
        }
        else{
            //int x = lower_bound(lis.begin(),lis.end(),num[i]);
            //lis[x] = num[i];
            int left = 0;
                int right = lis.size()-1;
                while(left < right){
                    int mid = (left+right)/2;
                    if(lis[mid] >= num[i]){
                        right = mid;
                    }
                    else{
                        left = mid+1;
                    }
                }
                lis[left] = num[i];
        }
    }
    cout<<lis.size();
    return 0;
}