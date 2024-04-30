#include<iostream>
#include<string>

using namespace std;

int main(void){
    int result = 0;
    string l,r;
    cin>>l>>r;
    if(l.length() != r.length()){
        cout<<"0";
    }
    else{
        for(int i = 0;i < r.length();i++){
            if(l[i] == r[i] && l[i] == '8'){
                result++;
            }
            else if(l[i] != r[i]){
                break;
            }
        }
        cout<<result;
    }
    return 0;
}