#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<vector<int>> lcs;

int main(void){
    int result = 0;
    string a,b;
    cin>>a>>b;
    lcs.assign(a.length()+1,vector<int>(b.length()+1,0));
    for(int i = 1;i <= a.length();i++){
        for(int j = 1;j <= b.length();j++){
            if(a[i-1] == b[j-1]){
                lcs[i][j] = lcs[i-1][j-1]+1;
            }
        }
    }
    for(int i = 1;i <= a.length();i++){
        for(int j = 1;j <= b.length();j++){
            if(lcs[i][j] > result){
                result = lcs[i][j];
            }
        }
    }
    cout<<result;
    return 0;
}