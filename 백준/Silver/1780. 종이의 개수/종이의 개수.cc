#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> paper;
int minusone,zero,one;

void dnq(int len,int x,int y){
    bool complete = true;
    int check = paper[x][y];
    for(int i = x;i < x+len;i++){
        for(int j = y;j < y+len;j++){
            if(check != paper[i][j]){
                for(int a = 0;a < 3;a++){
                    for(int b = 0;b < 3;b++){
                        dnq(len/3,len/3*a+x,len/3*b+y);
                    }
                }
                return ;
            }
        }
    }
    if(check == -1){
        minusone++;
    }
    else if(check == 0){
        zero++;
    }
    else{
        one++;
    }
}

int main(void){
    int n;
    cin>>n;
    paper.assign(n,vector<int>(n,0));
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            cin>>paper[i][j];
        }
    }
    dnq(n,0,0);
    cout<<minusone<<"\n"<<zero<<"\n"<<one;
    return 0;
}