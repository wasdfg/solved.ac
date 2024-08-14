#include<iostream>
#include<vector>

using namespace std;

int main(void){
    int n,m,k,x,y;
    cin>>n>>m>>k;
    vector<vector<int>> grid(n,vector<int>(m,1));
    x = (k-1)/m;
    y = (k-1)%m;
    for(int i = 1;i < n;i++){
        for(int j = 1;j < m;j++){
            grid[i][j] = grid[i][j-1]+grid[i-1][j];
        }
    }
    if(k == 0){
        cout<<grid[n-1][m-1];
    }
    else{
        cout<<grid[x][y]*grid[n-x-1][m-y-1];
    }
    return 0;
}