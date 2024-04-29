#include<iostream>
#include<string>

using namespace std;

int main(void){
    string s;
    int one = 0,zero = 0;
    cin>>s;
    for(int i = 0;i < s.length();i++){
        if(s[i] != s[i+1]){
            if(s[i] == '0'){
                zero++;
            }
            else{
                one++;
            }
        }
    }
    cout<<min(one,zero);
    return 0;
}