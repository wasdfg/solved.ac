#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<vector<int>> tri;
int n;

int main(void){
    cin>>n;
    tri.resize(n,vector<int>(n,0));
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            if(j > i){
                break;
            }
            cin>>tri[i][j];
            if(i > 0){
                if(j == 0){
                    tri[i][j] += tri[i-1][j];
                }
                else{
                    tri[i][j] += max(tri[i-1][j],tri[i-1][j-1]);
                } 
            }
        }
    }
    cout<<*max_element(tri[n-1].begin(),tri[n-1].end());
}