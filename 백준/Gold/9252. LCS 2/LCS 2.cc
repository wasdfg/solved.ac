#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main(void){
    int check = 0,x,y;
    string a,b;
    string answer = "";
    cin>>a>>b;
    x = a.length();
    y = b.length();
    vector<vector<int>> lcs(a.length()+1,vector<int>(b.length()+1,0));
    for(int i = 1;i <= a.length();i++){
        for(int j = 1;j <= b.length();j++){
            if(a[i-1] == b[j-1]){
                lcs[i][j] = lcs[i-1][j-1]+1;
                if(lcs[i][j] > check){
                    check = lcs[i][j];
                }
            }
            else{
                lcs[i][j] = max(lcs[i-1][j],lcs[i][j-1]);
                if(lcs[i][j] > check){
                    check = lcs[i][j];
                }
            }
        }
    }
    while(lcs[x][y] != 0){
        if(lcs[x][y] == lcs[x-1][y]){
            x--;
        }
        else if(lcs[x][y] == lcs[x][y-1]){
            y--;
        }
        else{
            answer+=a[x-1];
            x--;
            y--;
        }
    }
    reverse(answer.begin(),answer.end());
    cout<<check<<endl;
    cout<<answer;
    return 0;
}