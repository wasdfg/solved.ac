#include<iostream>
#include<vector>

using namespace std;
vector<vector<int>> fw;

int main(void){
    int N,M,a,b,c;
    cin>>N>>M;
    fw.resize(N,vector<int>(N,999999999));
    for(int i = 0;i < M;i++){
        cin>>a>>b>>c;
        if(fw[a-1][b-1] > c){
        fw[a-1][b-1] = c;
        }
    }
    for(int i = 0;i < N;i++){
        fw[i][i] = 0;
    }
    for(int k = 0;k < N;k++){
        for(int i = 0;i < N;i++){
            for(int j = 0;j < N;j++){
                fw[i][j] = min(fw[i][j],fw[i][k]+fw[k][j]);
            }
        }
    }
    for(int i = 0;i < N;i++){
        for(int j = 0;j < N;j++){
            if(fw[i][j] == 999999999){
                cout<<0<<" ";
            }
            else{
            cout<<fw[i][j]<<" ";
            }
        }
        cout<<endl;
    }
}