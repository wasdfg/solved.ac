#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<vector<int>> miro(1001,vector<int>(1001,0));

int main(void){
    int n,m;
    cin>>n>>m;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            cin>>miro[i][j];
        }
    }
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            miro[i][j] = miro[i][j]+max({miro[i-1][j],miro[i][j-1],miro[i-1][j-1]});
        }
    }
    cout<<miro[n][m];
    return 0;
}