#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(void){
    int t,i,a,b,c,d;
    int dx[9] = {-1,-1,1,1,-2,-2,2,2};
    int dy[9] = {-2,2,-2,2,1,-1,-1,1};
    vector<vector<int>> chess;
    cin>>t;
    for(int l = 0;l < t;l++){
        cin>>i;
        chess.assign(i,vector<int>(i,0));
        queue<pair<int,int>> togo;
        cin>>a>>b;
        cin>>c>>d;
        chess[a][b] = 1;
        togo.push({a,b});
        while(!togo.empty()){
            int x = togo.front().first;
            int y = togo.front().second;
            togo.pop();
            if(x == c && y == d){
                break;
            }
            for(int m = 0;m < 9;m++){
                if(x+dx[m] >= 0 && x+dx[m] < i && y+dy[m] >= 0 && y+dy[m] < i && chess[x+dx[m]][y+dy[m]] == 0){
                    chess[x+dx[m]][y+dy[m]] = chess[x][y] + 1;
                    togo.push({x+dx[m],y+dy[m]});
                }  
            }
        }
        cout<<chess[c][d]-1<<endl;
    }
    return 0;
}