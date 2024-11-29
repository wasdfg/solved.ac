#include<iostream>
#include<string>
#include<stack>

using namespace std;

int main(void){
    string s;
    int result,check = 1;
    while(1){
        result = 0;
        stack<char> x;
        cin>>s;
        if(s[0] == '-'){
            break;
        }
        for(int i = 0;i < s.length();i++){
            if(x.empty() || !(x.top() == '{' && s[i] == '}')){
                x.push(s[i]);
            }
            else{
                x.pop();
            }
        }
        while(!x.empty()){
            char a = x.top();
            x.pop();
            char b = x.top();
            x.pop();
            if(a == b){
                result++;
            }
            else{
                result+=2;
            }
        }
        cout<<check<<". "<<result<<"\n";
        check++;
    }
    return 0;
}