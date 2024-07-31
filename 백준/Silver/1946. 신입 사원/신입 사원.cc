#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void){
    int t,n,a,b,result;
    cin>>t;
    for(int i = 0;i < t;i++){
        result = 0;
        cin>>n;
        vector<pair<int,int>> recruit;
        for(int j = 0;j < n;j++){
            cin>>a>>b;
            recruit.push_back({a,b});
        }
        sort(recruit.begin(),recruit.end());
        int least = 100001;
        for(int j = 0;j < n;j++){
            if(least > recruit[j].second){
                result++;
                least = recruit[j].second;
            }
        }
        cout<<result<<endl;
    }
    return 0;
}