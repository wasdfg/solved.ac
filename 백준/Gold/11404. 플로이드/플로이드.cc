#include<iostream>
#include<vector>

using namespace std;

int main(void){
    int n,m,a,b,c;
    cin>>n>>m;
    vector<vector<int>> bus(n,vector<int>(n,1000000000));
    for(int i = 0;i < m;i++){
        cin>>a>>b>>c;
        bus[a-1][b-1] = min(c,bus[a-1][b-1]);
    }
    for(int i = 0;i < n;i++){
        bus[i][i] = 0;
    }
    for(int k = 0;k < n;k++){
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                bus[i][j] = min(bus[i][j],bus[i][k]+bus[k][j]);
            }
        }
    }
    for(int i = 0;i < n;i++){
        for(int j =0;j < n;j++){
            if(bus[i][j] == 1000000000){
                cout<<"0 ";
            }
            else{
                cout<<bus[i][j]<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}