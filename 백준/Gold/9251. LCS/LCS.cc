#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main(void){
    int result = 0;
    string a,b;
    cin>>a>>b;
    vector<vector<int>> lcs(a.length()+1,vector<int>(b.length()+1,0));
    for(int i = 1;i <= a.length();i++){
        for(int j = 1;j <= b.length();j++){
            if(a[i-1] == b[j-1]){
                lcs[i][j] = lcs[i-1][j-1]+1;
            }
            else{
                lcs[i][j] = max(lcs[i-1][j],lcs[i][j-1]);
            }
            if(lcs[i][j] > result){
                result = lcs[i][j];
            }
        }
    }
    cout<<result;
    return 0;
}