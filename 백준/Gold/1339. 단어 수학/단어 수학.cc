#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main(void){
    int n,result = 0,x = 9;
    cin>>n;
    vector<int> alpha(26,0);
    for(int i = 0;i < n;i++){
        string s;
        cin>>s;
        int a = 1;
        for(int j = s.length()-1;j >= 0;j--){
            alpha[s[j]-'A']+=a;
            a*=10;
        }
    }
    sort(alpha.begin(),alpha.end(),greater<int>());
    for(int i = 0;i < 26;i++){
        if(alpha[i] == 0){
            break;
        }
        else{
            result+=(alpha[i]*x);
            x--;
        }
    }
    cout<<result;
    return 0;
}