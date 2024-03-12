#include<iostream>
#include<vector>
#include<string>
#include<set>

using namespace std;

set<int> check;
vector<vector<int>> jump(5,vector<int>(5,0));
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};

int dfs(int x,int y,int num,int count){
    if(count == 5){
        if(check.find(num) == check.end()){
            check.insert(num);
        }
        return 0;
    }
    for(int i = 0;i < 4;i++){
        if(x+dx[i] >= 0 && x+dx[i] < 5 && y+dy[i] >= 0 && y+dy[i] < 5){
            dfs(x+dx[i],y+dy[i],num*10+jump[x+dx[i]][y+dy[i]],count+1);
        }
    }
    return 0;
}

int main(void){
    for(int i = 0;i < 5;i++){
        for(int j = 0;j < 5;j++){
            cin>>jump[i][j];
        }
    }
    for(int i = 0;i < 5;i++){
        for(int j = 0;j < 5;j++){
            dfs(i,j,jump[i][j],0);
        }
    }
    cout<<check.size();
    return 0;
}