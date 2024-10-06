#include<iostream>
#include<vector>
#include<string>

using namespace std;

string s;
vector<vector<int>> quad;

void dnq(int len,int x,int y){
    int check = quad[x][y];
    for(int i = x;i < x+len;i++){
        for(int j = y;j < y+len;j++){
            if(quad[i][j] != check){
                s+="(";
                for(int a = 0;a < 2;a++){
                    for(int b = 0;b < 2;b++){
                        dnq(len/2,a*len/2+x,b*len/2+y);
                    }
                }
                s+=")";
                return ;
            }
        }
    }
    s+=to_string(check);
}

int main(void){
    int n,zero = 0,one = 0;
    cin>>n;
    quad.assign(n,vector<int>(n,0));
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            scanf("%1d",&quad[i][j]);
        }
    }
    dnq(n,0,0);
    cout<<s;
    return 0;
}