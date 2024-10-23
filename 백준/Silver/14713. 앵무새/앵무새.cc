#include<iostream>
#include<queue>
#include<vector>
#include<string>
#include<sstream>

using namespace std;

int main(void){
    int n;
    bool check = false;
    string s,l,tmp;
    cin>>n;
    cin.ignore();
    vector<queue<string>> parrot(n);
    for(int i = 0;i < n;i++){
        getline(cin,s);
        stringstream ss(s);
        while(ss >> tmp){
            parrot[i].push(tmp);
        }
    }
    getline(cin,l);
    stringstream ss(l);
    while(ss >> tmp){
        check = false;
        for(int i = 0;i < n;i++){
            if(!parrot[i].empty() && tmp == parrot[i].front()){
                check = true;
                parrot[i].pop();
                break;
            }
        }
        if(check == false){
            cout<<"Impossible";
            return 0;
        }
    }
    for(int i = 0;i < n;i++){
        if(!parrot[i].empty()){
            cout<<"Impossible";
            return 0;
        }
    }
    cout<<"Possible";
    return 0;
}