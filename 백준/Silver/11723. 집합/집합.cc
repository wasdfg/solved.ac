#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main(void){
    int M,num,S = 0;
    string command;
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin>>M;
    for(int i = 0;i < M;i++){
        cin>>command;
        if(command.compare("add") == 0){
            cin>>num;
            S |= (1<<(num-1));
        }
        else if(command.compare("remove") == 0){
            cin>>num;
            S &= (((1<<20)-1) - (1<<(num-1)));
        }
        else if(command.compare("check") == 0){
            cin>>num;
            if((S & (1<<(num-1))) == (1<<(num-1))){
                cout<<"1\n";
            }
            else{
                cout<<"0\n";
            }
        }
        else if(command.compare("toggle") == 0){
            cin>>num;
            S ^= (1<<(num-1));
        }
        else if(command.compare("all") == 0){
            S |= ((1<<20)-1);
        }
        else if(command.compare("empty") == 0){
            S &= 0;
        }
    }
}