#include<iostream>
#include<set>
#include<string>

using namespace std;

int main(void){
    string s;
    cin>>s;

    set<string> sub;
    for(int i = 0; i < s.size(); i++){
        for(int j = 1; j + i <= s.size(); j++) {
            sub.insert(s.substr(i, j));
        }
    }
    cout<<sub.size()<<'\n';
    return 0;
}