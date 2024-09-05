#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void){
    int n,m,a,b,check = 999999999,kb = 0,result = 0;
    cin>>n>>m;
    vector<vector<int>> dist(n,vector<int>(n,999999999));
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
                dist[i][j] = min(dist[i][k]+dist[k][j],dist[i][j]);
            }
        }
    }
    for(int i = 0;i < n;i++){
        kb = 0;
        for(int j = 0;j < n;j++){
            if(i == j || dist[i][j] == 999999999){
                continue;
            }
            else{
                kb+=dist[i][j];
            }
        }
        if(check > kb){
            check = kb;
            result = i+1;
        }
    }
    cout<<result;
    return 0;
}