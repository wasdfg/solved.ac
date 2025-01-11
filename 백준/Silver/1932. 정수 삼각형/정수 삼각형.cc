#include<iostream>
#include<vector>

using namespace std;

int main(void){
    int n,x = 0;
    cin>>n;
    vector<vector<int>> tri(n,vector<int>(n+1,0));
    for(int i = 0;i < n;i++){
        for(int j = 0;j < i+1;j++){
            cin>>tri[i][j];
        }
    }
    for(int i = 1;i < n;i++){
        for(int j = 0;j < i+1;j++){
            if(j == 0){
                tri[i][0]+=tri[i-1][0];
            }
            else{
                tri[i][j]+=max(tri[i-1][j],tri[i-1][j-1]);
            }
        }
    }
    for(int i = 0;i < n+1;i++){
        x = max(x,tri[n-1][i]);
    }
    cout<<x;
    return 0;
}