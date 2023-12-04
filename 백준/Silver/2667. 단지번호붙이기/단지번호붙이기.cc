#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int area,size;
vector<vector<int>> home;

int dfs(int i,int j){
    area++;
    if(i - 1 >= 0 && i - 1 < size && home[i-1][j] == 1){
        home[i-1][j] = 0;
        dfs(i-1,j);
    }
    if(i + 1 >= 0 && i + 1 < size && home[i+1][j] == 1){
        home[i+1][j] = 0;
        dfs(i+1,j);
    }
    if(j - 1 >= 0 && j - 1 < size && home[i][j-1] == 1){
        home[i][j-1] = 0;
        dfs(i,j-1);
    }
    if(j + 1 >= 0 && j + 1 < size && home[i][j+1] == 1){
        home[i][j+1] = 0;
        dfs(i,j+1);
    }
    return 0;
}

int main(void){
    int num;
    cin>>size;
    home = vector<vector<int>>(size);
    vector<int> areas;
    for(int i = 0;i < size;i++){
        for(int j = 0;j < size;j++){
        scanf("%1d",&num);
        home[i].push_back(num);
        }
    }

    for(int i = 0;i < size;i++){
        for(int j = 0;j < size;j++){
            if(home[i][j] == 1){
                home[i][j] = 0;
                area = 0;
                dfs(i,j);
                areas.push_back(area);
            }
        }
    }
    stable_sort(areas.begin(),areas.end());
    cout<<areas.size()<<endl;
    for(int i = 0;i < areas.size();i++){
        cout<<areas[i]<<endl;
    }
}