#include<iostream>
#include<vector>

using namespace std;

int main(void){
    int n,m,b,diff = 64000001,height,result = 0;
    cin>>n>>m>>b;
    vector<vector<int>> zido(n,vector<int>(m,0));
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            cin>>zido[i][j];
        }
    }
    for(int a = 0;a < 257;a++){
        int add = 0;
        int remove = 0;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(zido[i][j] > a){
                    remove+=(zido[i][j] - a);
                }
                else if(zido[i][j] < a){
                    add+=(a - zido[i][j]);
                }
            }
        }
        if(remove + b >= add){
            int check = remove * 2 + add;
            if(diff >= check){
                diff = check;
                height = a;
            }
        }
    }
    cout<<diff<<" "<<height;
    return 0;
}