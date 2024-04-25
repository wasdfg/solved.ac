#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main(void){
    int len = 0;
    string s;
    cin>>s;
    string result = "";
    for(auto a:s){
        if(a == 'X'){
            len++;
        }
        else{
            if(len % 2 != 0){
                cout<<"-1";
                return 0;
            }
            else{
                for(int i = 0;i < len/4*4;i++){
                    result.push_back('A');
                }
                len-=(len/4*4);
                for(int i = 0;i < len/2*2;i++){
                    result+='B';
                }
            }
            len = 0;
            result+='.';
        }
    }
    if(len % 2 != 0){
        cout<<"-1";
        return 0;
    }
    else{
        for(int i = 0;i < len/4*4;i++){
            result.push_back('A');
        }
        len-=(len/4*4);
        for(int i = 0;i < len/2*2;i++){
            result+='B';
        }
    }
    cout<<result;
    return 0;
}