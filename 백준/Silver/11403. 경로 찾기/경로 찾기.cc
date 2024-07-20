#include<iostream>
#include<vector>

using namespace std;


int main(void){
    int n,x;
    cin>>n;
    vector<vector<int>> g(n,vector<int>(n,0));
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            cin>>g[i][j];
            if(g[i][j] == 0){
                g[i][j] = 10000;
            }
        }
    }
    for(int k = 0;k < n;k++){
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                g[i][j] = min(g[i][j],g[i][k]+g[k][j]);
            }
        }
    }
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            if(g[i][j] == 10000 || g[i][j] == 0){
                cout<<"0 ";
            }
            else{
                cout<<"1 ";
            }
        }
        cout<<endl;
    }
    return 0;
}