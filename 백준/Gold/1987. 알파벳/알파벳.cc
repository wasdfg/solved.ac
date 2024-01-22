#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<bool> check(26,0);
vector<vector<int>> alpha;

int R,C;
int tx[4] = {0,0,-1,1};
int ty[4] = {1,-1,0,0};
int result;

int dfs(int x,int y,int count){
    result = max(result,count);
    for(int i = 0;i < 4;i++){
        if(x+tx[i] >= 0 && x+tx[i] < R && y+ty[i] >= 0 && y+ty[i] < C){
            if(check[alpha[x+tx[i]][y+ty[i]]] == false){
                check[alpha[x+tx[i]][y+ty[i]]] = true;
                dfs(x+tx[i],y+ty[i],count+1);
                check[alpha[x+tx[i]][y+ty[i]]] = false;
            }
        }
    }
    return 0;
}

int main(void){
    
    cin>>R>>C;
    alpha.resize(R,vector<int>());
    for(int i = 0;i < R;i++){
        string s;
        cin>>s;
        for(char c:s){
            alpha[i].push_back(c-'A');
        }
    }
    check[alpha[0][0]] = true;
    dfs(0,0,1);
    cout<<result;
    return 0;
}