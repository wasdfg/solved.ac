#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(void){
    int I,t,startx,starty,endx,endy;
    int tx[9] = {-1,-1,1,1,-2,-2,2,2};
    int ty[9] = {-2,2,-2,2,1,-1,-1,1};
    vector<vector<int>> chess;
    queue<pair<int,int>> togo;
    cin>>t;
    for(int s = 0;s < t;s++){
        cin>>I;
        chess.assign(I,vector<int>(I,999999999));
        cin>>startx>>starty;
        cin>>endx>>endy;
        togo.push({startx,starty});
        chess[startx][starty] = 0;
        while(!togo.empty()){
            int x = togo.front().first;
            int y = togo.front().second;
            togo.pop();
            if(x == endx && y == endy){
                break;
            }
            for(int j = 0;j < 8;j++){
                if(x+tx[j] >= 0 && x+tx[j] < I && y+ty[j] >= 0 && y+ty[j] < I && chess[x+tx[j]][y+ty[j]] == 999999999){
                    chess[x+tx[j]][y+ty[j]] = min(chess[x][y] + chess[x+tx[j]][y+ty[j]],chess[x][y]+1);
                    togo.push({x+tx[j],y+ty[j]});
                }
            }
        }
        while(!togo.empty()){
            togo.pop();
        }
        cout<<chess[endx][endy]<<endl;
    }
    return 0;
}