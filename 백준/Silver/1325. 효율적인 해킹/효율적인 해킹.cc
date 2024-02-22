#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

vector<int> togo[100000];
vector<bool> visited;
int result;

int dfs(int x){
    visited[x] = true;
    result++;
    for(int i = 0;i < togo[x].size();i++){
        if(visited[togo[x][i]] == false){
            dfs(togo[x][i]);
        }
    }
    return 0;
}

int main(void){
    int N,M,A,B;
    cin>>N>>M;
    vector<int> maxi;
    for(int i = 0;i < M;i++){
        cin>>A>>B;
        togo[B-1].push_back(A-1);
    }
    int check = 0;
    for(int i = 0;i < N;i++){
        visited.assign(N,0);
        result = 0;
        dfs(i);
        if(check == result){
            maxi.push_back(i+1);
        }
        else if(check < result){
            maxi.clear();
            check = result;
            maxi.push_back(i+1);
        }

    }
    sort(maxi.begin(),maxi.end());
    for(int i = 0;i < maxi.size();i++){
            cout<<maxi[i]<<" ";
    }
    return 0;
}