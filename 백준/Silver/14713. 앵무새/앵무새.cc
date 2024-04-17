#include<iostream>
#include<queue>
#include<vector>
#include<string>
#include<sstream>

using namespace std;

int main(void){
    int n,scount = 0,lcount = 0;
    string s,L;
    cin>>n;
    cin.ignore(5,'\n');
    vector<queue<string>> word(n);
    for(int i = 0;i < n;i++){
        getline(cin,s);
        istringstream ss(s);
        string str_buf;
        while(getline(ss,str_buf,' ')){
            word[i].push(str_buf);
            scount++;
        }
    }
    getline(cin,L);
    istringstream ss(L);
    string str_buf;
    bool check;
    while(getline(ss,str_buf,' ')){
        check = false;
        lcount++;
        for(int i = 0;i < n;i++){
            if(!word[i].empty() && word[i].front().compare(str_buf) == 0){
                word[i].pop();
                check = true;
                break;
            }
        }
        if(check == false){
            cout<<"Impossible";
            return 0;
        }
    }
    if(lcount != scount){
        cout<<"Impossible";
    }
    else{
        cout<<"Possible";
    }
    return 0;
}