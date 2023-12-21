#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> paper;
int N,wpaper = 0,bpaper = 0;
bool same;

int dq(int x,int y,int len){
    int color = paper[x][y];
    same = true;
    for(int i = x;i < x+len;i++){
        for(int j = y;j < y+len;j++){
            if(paper[i][j] != color){
                same = false;
                break;
            }
        }
    }
    if(!same){
        dq(x,y,len/2);
        dq(x,y+len/2,len/2);
        dq(x+len/2,y,len/2);
        dq(x+len/2,y+len/2,len/2);
    }
    else{
        if(color == 0){
            wpaper++;
        }
        else{
            bpaper++;
        }
    }
    return 0;
}

int main(void){
    cin>>N;
    paper.resize(N,vector<int>(N,0));
    for(int i = 0;i < N;i++){
        for(int j = 0;j < N;j++){
            cin>>paper[i][j];
        }
    }
    dq(0,0,N);
    cout<<wpaper<<"\n"<<bpaper;
    return 0;
}