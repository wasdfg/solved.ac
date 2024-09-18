#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main(void){
    int check = 0,x,y;
    string a,b;
    string result;
    cin>>a>>b;
    x = a.length()+1;
    y = b.length()+1;
    vector<vector<int>> lcs(x,vector<int>(y,0));
    for(int i = 1;i < x;i++){
        for(int j = 1;j < y;j++){
            if(a[i-1] == b[j-1]){
                lcs[i][j] = lcs[i-1][j-1]+1;
            }
            else{
                lcs[i][j] = max(lcs[i-1][j],lcs[i][j-1]);
            }
        }
    }
    x--;
    y--;
    while(1){
        if(lcs[x][y] == 0){
            break;
        }
        if(lcs[x][y] == lcs[x-1][y]){
            x--;
        }
        else if(lcs[x][y] == lcs[x][y-1]){
            y--;
        }
        else{
            check++;
            result+=a[x-1];
            x--;
            y--;
        }
    }
    cout<<check<<endl;
    if(check != 0){
        reverse(result.begin(),result.end());
        cout<<result;
    }
    return 0;
}