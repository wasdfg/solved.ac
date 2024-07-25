#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<bool> check(26,0);
vector<string> alpha;

int r,c;
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
int result = 0;

void dfs(int x,int y,int len){
    result = max(len,result);
    for(int i = 0;i < 4;i++){
        if(x+dx[i] >= 0 && x+dx[i] < r && y+dy[i] >= 0 && y+dy[i] < c && check[alpha[x+dx[i]][y+dy[i]]-'A'] == 0){
            check[alpha[x+dx[i]][y+dy[i]]-'A'] = 1;
            dfs(x+dx[i],y+dy[i],len+1);
            check[alpha[x+dx[i]][y+dy[i]]-'A'] = 0;
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin>>r>>c;
    for(int i = 0;i < r;i++){
        cin>>s;
        alpha.push_back(s);
    }
    check[alpha[0][0]-'A'] = 1;
    dfs(0,0,1);
    cout<<result;
    return 0;
}