#include<iostream>
#include<deque>
#include<string>
#include<algorithm>

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t,n;
    string p,x;
    cin>>t;
    for(int i = 0;i < t;i++){
        cin>>p>>n>>x;
        deque<int> num;
        bool checkerror = false;
        bool foward = true;
        string tonum = "";
        for(int len = 0;len < x.length();len++){
            if(x[len] >= '0' && x[len] <= '9'){
                tonum+=x[len];
            }
            if(x[len] == ',' || x[len] == ']'){
                if(tonum.size() != 0){
                    num.push_back(stoi(tonum));
                }
                tonum = "";
            }
        }
        for(int len = 0;len < p.length();len++){
            if(p[len] == 'R'){
                foward = !foward;
            }
            if(p[len] == 'D'){
                if(num.empty()){
                    checkerror = true;
                    break;
                }
                if(foward == true){
                    num.pop_front();
                }
                else{
                    num.pop_back();
                }
            }
        }
        if(checkerror == true){
            cout<<"error\n";
        }
        else{
            cout<<"[";
            while(!num.empty()){
                if(foward == true){
                    cout<<num.front();
                    num.pop_front();
                }
                else{
                    cout<<num.back();
                    num.pop_back();
                }
                if(num.size() > 0){
                    cout<<",";
                }
            }
            cout<<"]\n";
        }
    }
    return 0;
}