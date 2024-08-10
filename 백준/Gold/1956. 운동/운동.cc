#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(void){
    int v,e,a,b,c,result = 200000000;
    cin>>v>>e;
    vector<vector<int>> graph(v,vector<int>(v,200000000));
    for(int i = 0;i < e;i++){
        cin>>a>>b>>c;
        graph[a-1][b-1] = c;
    }
    for(int i = 0;i < v;i++){
        graph[i][i] = 0;
    }
    for(int k = 0;k < v;k++){
        for(int i = 0;i < v;i++){
            for(int j = 0;j < v;j++){
                graph[i][j] = min(graph[i][k]+graph[k][j],graph[i][j]);
            }
        }
    }
    for(int i = 0;i < v;i++){
        for(int j = i+1;j < v;j++){
            if(graph[i][j] != 200000000 && graph[j][i] != 200000000){
                result = min(result,graph[i][j]+graph[j][i]);
            }
        }
    }
    if(result >= 200000000){
        cout<<"-1";
    }
    else{
        cout<<result;
    }
    return 0;
}