#include<iostream>

using namespace std;

int w[101][101][101];

int main(void){
    int a,b,c;
    fill_n(w[0][0],101*101*101,1);
    for(int i = 51;i < 71;i++){
        for(int j = 51;j < 71;j++){
            for(int k = 51;k < 71;k++){
                if(i < j && j < k){
                    w[i][j][k] = w[i][j][k-1]+w[i][j-1][k-1]-w[i][j-1][k];
                }
                else{
                    w[i][j][k] = w[i-1][j][k]+w[i-1][j-1][k]+w[i-1][j][k-1]-w[i-1][j-1][k-1];
                }
            }
        }
    }
    for(int i = 51;i < 101;i++){
        for(int j = 51;j < 101;j++){
            for(int k = 51;k < 101;k++){
                if(i >= 71 || j >= 71 || k >= 71){
                    w[i][j][k] = w[70][70][70];
                }
            }
        }
    }
    while(1){
        cin>>a>>b>>c;
        if(a == -1 && b == -1 && c == -1){
            return 0;
        }
        else{
            cout<<"w("<<a<<", "<<b<<", "<<c<<") = "<<w[a+50][b+50][c+50]<<"\n";
        }
    }
    return 0;
}