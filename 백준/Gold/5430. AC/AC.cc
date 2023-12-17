#include<iostream>
#include<deque>
#include<string>

using namespace std;

int main(void){
    int T,n,num;
    bool reverse,error;
    string p,array;
    cin>>T;
    for(int i = 0;i < T;i++){
        cin>>p;
        cin>>n;
        cin>>array;
        string s = "";
        deque<int> X;
        reverse = false;
        error = false;
        for(int j = 0;j < array.length();j++){
            if(isdigit(array[j])){
                s+=array[j];
            }
            else{
                if(!s.empty()){
                    X.push_back(stoi(s));
                    s = "";
                }
            }
        }
        for(int j = 0;j < p.size();j++){
            if(p[j] == 'R'){
                reverse = (!reverse);
            }
            else if(p[j] == 'D'){
                if(X.size() < 1){
                    error = true;
                    break;
                }
                else{
                    if(reverse == true){
                        X.pop_back();
                    }
                    else{
                        X.pop_front();
                    }
                }
            }
        }
        if(error == true){
            cout<<"error\n";
        }
        else{
            cout<<"[";
            if(reverse == false){
            for(int j = 0;j < X.size();j++){
                cout<<X[j];
                if(j < X.size() - 1){
                    cout<<",";
                }
            }
            }
            else{
                for(int j = X.size()-1;j >= 0;j--){
                cout<<X[j];
                if(j > 0){
                    cout<<",";
                }
            }
            }
            cout<<"]\n";
        }
    }
}