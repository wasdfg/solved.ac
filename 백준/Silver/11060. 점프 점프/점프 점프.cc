#include<iostream>
#include<vector>

using namespace std;

int main(void){
    int n,a;
    cin>>n;
    vector<vector<int>> miro(n,vector<int>(2,999999999));
    for(int i = 0;i < n;i++){
        cin>>miro[i][0];
    }
    miro[0][1] = 0;
    for(int i = 0;i < n;i++){
        for(int j = 1;j <= miro[i][0];j++){
            if(i+j < n){
                miro[i+j][1] = min(miro[i+j][1],miro[i][1]+1);
            }
        }
    }
    if(miro[n-1][1] != 999999999){
        cout<<miro[n-1][1];
    }
    else{
        cout<<"-1";
    }
    return 0;
}