#include<iostream>
#include<deque>
#include<string>
#include<algorithm>

using namespace std;

int main(void){
    int t,n;
    string p,x;
    cin>>t;
    for(int i = 0;i < t;i++){
        deque<int> num;
        string chgnum = "";
        bool error = 0,back = 0;
        cin>>p>>n>>x;
        for(int j = 1;j < x.length();j++){
            if(x[1] == ']'){
                break;
            }
            if(x[j] >= 48 && x[j] < 58){
                chgnum+=(x[j]);
            }
            else{
                num.push_back(stoi(chgnum));
                chgnum = "";
            }
        }
        for(int j = 0;j < p.length();j++){
            if(p[j] == 'R'){
                back = !back;
            }
            else{
                if(num.empty()){
                    error = 1;
                }
                else{
                    if(back == 0){
                        num.pop_front();
                    }
                    else{
                        num.pop_back();
                    }
                }
            }
        }
        if(error == 1){
            cout<<"error\n";
        }
        else{
            cout<<"[";
            if(back == 1){
                for(int j = num.size()-1;j >= 0;j--){
                    cout<<num[j];
                    if(j > 0){
                        cout<<",";
                    }
                }
            }
            else{
                for(int j = 0;j < num.size();j++){
                    cout<<num[j];
                    if(j < num.size() - 1){
                        cout<<",";
                    }
                }
            }
            cout<<"]\n";
        }
    }
    return 0;
}