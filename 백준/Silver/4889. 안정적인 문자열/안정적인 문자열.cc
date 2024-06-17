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
        for(int i = 0;i < s.length();i++){
            if(s[i] == '-'){
                return 0;
            }
            else{
                if(!x.empty() && x.top() == '{' && s[i] == '}'){
                    x.pop();
                }
                else{
                    x.push(s[i]);
                }
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
        cout<<check<<". "<<result<<endl;
        check++;
    }
    return 0;
}