#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main(void){
    int check = 0,center;
    string s;
    string result = "";
    string opp = "";
    cin>>s;
    vector<int> alpha(26,0);
    for(int i = 0;i < s.length();i++){
        alpha[s[i]-65]++;
    }
    for(int i = 0;i < 26;i++){
        if(alpha[i] != 0){
            if(alpha[i] % 2 == 1){
                check++;
                center = i;
            }
        }
    }
    if(check > 1){
        cout<<"I'm Sorry Hansoo";
    }
    else{
        for(int i = 0;i < 26;i++){
            if(alpha[i] > 0){
                for(int j = 0;j < alpha[i]/2;j++){
                    result+=(i+'A');
                }
            }
        }
        opp = result;
        reverse(opp.begin(),opp.end());
        if(check == 1){
            result+=(center+'A');
        }
        cout<<result+opp;
    }
    return 0;
}