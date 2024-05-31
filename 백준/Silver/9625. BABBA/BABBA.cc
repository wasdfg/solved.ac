#include<iostream>
#include<vector>

using namespace std;

int main(void){
    int k;
    cin>>k;
    vector<vector<int>> ab(k+1,vector<int>(2,0));
    ab[0][0] = 1;
    ab[0][1] = 0;
    ab[1][0] = 0;
    ab[1][1] = 1;
    for(int i = 2;i < k+1;i++){
        ab[i][0] = ab[i-1][1];
        ab[i][1] = ab[i-1][0]+ab[i-1][1];
    }
    cout<<ab[k][0]<<" "<<ab[k][1];
    return 0;
}