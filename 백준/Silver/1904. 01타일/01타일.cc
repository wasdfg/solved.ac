#include<iostream>
#include<vector>

using namespace std;

int main(void){
    int n;
    cin>>n;
    vector<int> zo(n,0);
    if(n > 2){
        zo[0] = 1;
        zo[1] = 2;
        for(int i = 2;i < n;i++){
            zo[i] = ((zo[i-1] % 15746) + (zo[i-2] % 15746)) % 15746;
        }
        cout<<zo[n-1] % 15746;
    }
    else{
        if(n == 1){
            cout<<"1";
        }
        else{
            cout<<"2";
        }
    }
    return 0;
}