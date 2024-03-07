#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void){
    int n,m,a,b,check = 999999999,kb = 0;
    cin>>n>>m;
    vector<vector<int>> dist(n,vector<int>(n,999999999));
    vector<int> big;
    for(int i = 0;i < m;i++){
        cin>>a>>b;
        dist[a-1][b-1] = 1;
        dist[b-1][a-1] = 1;
    }
    for(int i = 0;i < n;i++){
        dist[i][i] = 0;
    }
    for(int k = 0;k < n;k++){
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);
            }
        }
    }
    for(int i = 0;i < n;i++){
        kb = 0;
        for(int j = 0;j < n;j++){
            kb+=dist[i][j];
        }
        if(kb < check){
            check = kb;
            big.clear();
            big.push_back(i+1);
        }
        else if(kb == check){
            big.push_back(i+1);
        }
    }
    sort(big.begin(),big.end());
    cout<<big.front();
    return 0;
}