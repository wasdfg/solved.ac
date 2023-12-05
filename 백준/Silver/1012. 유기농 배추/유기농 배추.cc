#include<iostream>
#include<vector>

using namespace std;

int lenght,height,count;
vector<vector<int>> bat;

int dfs(int i,int j){
    if(i - 1 >= 0 && i - 1 < lenght && bat[i-1][j] == 1){
        bat[i-1][j] = 0;
        dfs(i-1,j);
    }
    if(i + 1 >= 0 && i + 1 < lenght && bat[i+1][j] == 1){
        bat[i+1][j] = 0;
        dfs(i+1,j);
    }
    if(j - 1 >= 0 && j - 1 < height && bat[i][j-1] == 1){
        bat[i][j-1] = 0;
        dfs(i,j-1);
    }
    if(j + 1 >= 0 && j + 1 < height && bat[i][j+1] == 1){
        bat[i][j+1] = 0;
        dfs(i,j+1);
    }
    return 0;
}

int main(void){
    int tcase,baechu,x,y;
    cin>>tcase;
    for(int i = 0;i < tcase;i++){
    count = 0;
    cin>>lenght>>height>>baechu;
    bat = vector<vector<int>>(lenght,vector<int>(height,0));
    for(int i = 0;i < baechu;i++){
        cin>>x>>y;
        bat[x][y] = 1;
    }
    for(int i = 0;i < lenght;i++){
        for(int j = 0;j < height;j++){
            if(bat[i][j] == 1){
                bat[i][j] = 0;
                dfs(i,j);
                count++;
            }
        }
    }
    cout<<count<<endl;
    }
}