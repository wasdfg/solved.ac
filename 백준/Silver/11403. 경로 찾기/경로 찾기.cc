#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> fw;

int main(void){
    int N,x;
    cin>>N;
    fw.resize(N,vector<int>(N,0));
    for(int i = 0;i < N;i++){
        for(int j = 0;j < N;j++){
            cin>>x;
            if(x == 0){
                fw[i][j] =99999999;
            }
            else{
                fw[i][j] = x;
            }
        }
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
            if(fw[i][j] > 0 && fw[i][j] < 99999999){
                fw[i][j] = 1;
            }
            else{
                fw[i][j] = 0;
            }
        }
    }
    for(int i = 0;i < N;i++){
        for(int j = 0;j < N;j++){
            cout<<fw[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}