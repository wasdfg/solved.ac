#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void){
    int n,result = -1;
    cin>>n;
    vector<int> tri(n,0);
    for(int i = 0;i < n;i++){
        cin>>tri[i];
    }
    sort(tri.begin(),tri.end(),greater<int>());
    for(int i = 0;i < n-2;i++){
        int left = i+1;
        int right = left+1;
        while(left < right){
            if(tri[i] < tri[left]+tri[right]){
                if(result < tri[i]+tri[left]+tri[right]){
                    result = tri[i]+tri[left]+tri[right];
                }
                left++;
            }
            else{
                right--;
            }
        }
    }
    cout<<result;
    return 0;
}