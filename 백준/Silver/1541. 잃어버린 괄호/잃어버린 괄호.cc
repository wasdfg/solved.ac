#include<iostream>
#include<string>

using namespace std;

int main(void){
    int num = 0;
    bool minus = false;
    string a,tonum = "";
    cin>>a;
    for(int i = 0;i <= a.length();i++){
        if(a[i] == '-' || a[i] == '+' || i == a.length()){
            if(minus){
                num -= stoi(tonum);
                tonum = "";
            }
            else{
                num += stoi(tonum);
                tonum = "";
            }
        }
        else{
            tonum+=a[i];
        }
        if(a[i] == '-'){
            minus = true;
        }
    }
    cout<<num;
}