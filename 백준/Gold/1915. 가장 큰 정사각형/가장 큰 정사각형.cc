#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void){
    int n,m,result = 0;
    cin>>n>>m;
    vector<vector<int>> square(n+1,vector<int>(m+1,0));
    for(int i = 1;i < n+1;i++){
        for(int j = 1;j < m+1;j++){
            scanf("%1d",&square[i][j]);
        }
    }
    for(int i = 1;i < n+1;i++){
        for(int j = 1;j < m+1;j++){
            if(square[i][j] == 1){
                square[i][j] = min({square[i-1][j],square[i-1][j-1],square[i][j-1]})+1;
                result = max(square[i][j],result);
            }
        }
    }
    cout<<result*result;
    return 0;
}