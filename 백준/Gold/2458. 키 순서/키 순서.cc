#include<iostream>
#include<vector>

using namespace std;

int main(void){
    int n,m,a,b,result = 0;
    cin>>n>>m;
    vector<vector<int>> height(n,vector<int>(n,501));
    for(int i = 0;i < m;i++){
        cin>>a>>b;
        height[a-1][b-1] = 1;
    }
    for(int k = 0;k < n;k++){
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                height[i][j] = min(height[i][j],height[i][k]+height[k][j]);
            }
        }
    }
    for(int i = 0;i < n;i++){
        bool can = 1;
        for(int j = 0;j < n;j++){
            if(i == j){
                continue;
            }
            if(height[i][j] == 501 && height[j][i] == 501){
                can = 0;
                break;
            }
        }
        if(can){
            result++;
        }
    }
    cout<<result;
    return 0;
}