#include<iostream>
#include<vector>
#include<set>

using namespace std;

set<int> check;
vector<vector<int>> jump(5,vector<int>(5,0));
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
int n;

void dfs(int x,int y,int count,int result){
    if(count == 6){
        check.insert(result);
        return;
    }
    else{
        for(int i = 0;i < 4;i++){
            if(x+dx[i] >= 0 && x+dx[i] < 5 && y+dy[i] >= 0 && y+dy[i] < 5){
                dfs(x+dx[i],y+dy[i],count+1,result*10+jump[x+dx[i]][y+dy[i]]);
            }
        }
    }
}

int main(void){
    for(int i = 0;i < 5;i++){
        for(int j = 0;j < 5;j++){
            cin>>jump[i][j];
        }
    }
    for(int i = 0;i < 5;i++){
        for(int j = 0;j < 5;j++){
            n = 0;
            dfs(i,j,1,jump[i][j]);
        }
    }
    cout<<check.size();
    return 0;
}