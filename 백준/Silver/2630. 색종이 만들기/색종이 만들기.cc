#include<iostream>
#include<vector>

using namespace std;

int n,zero = 0,one = 0;
vector<vector<int>> paper;

int dq(int x,int y,int len){
    int now = paper[x][y];
    bool complete = 1;
    for(int i = x;i < x+len;i++){
        for(int j = y;j < y+len;j++){
            if(paper[i][j] != now){
                complete = 0;
                break;
            }
        }
    }
    if(complete == 0){
        dq(x+len/2,y,len/2);
        dq(x,y+len/2,len/2);
        dq(x+len/2,y+len/2,len/2);
        dq(x,y,len/2);
    }
    else{
        if(paper[x][y] == 1){
            one++;
        }
        else{
            zero++;
        }
    }
    return 0;
}

int main(void){
    cin>>n;
    paper.assign(n,vector<int>(n,0));
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            cin>>paper[i][j];
        }
    }
    dq(0,0,n);
    cout<<zero<<endl<<one;
    return 0;
}