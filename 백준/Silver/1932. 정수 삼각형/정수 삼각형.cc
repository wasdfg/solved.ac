#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void){
    int n,x;
    cin>>n;
    vector<vector<int>> tri(n,vector<int>(n+1,0));
    for(int i = 0;i < n;i++){
        for(int j = 0;j < i+1;j++){
            cin>>tri[i][j];
        }
    }
    for(int i = 1;i < tri.size();i++){
        for(int j = 0;j < i+1;j++){
            if(j == 0){
                tri[i][j]+=tri[i-1][j];
            }
            else{
                tri[i][j]+=max({tri[i-1][j],tri[i-1][j-1]});
            }
        }
    }
    cout<<*max_element(tri[n-1].begin(),tri[n-1].end());
    return 0;
}