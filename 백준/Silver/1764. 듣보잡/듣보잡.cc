#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<algorithm>

using namespace std;

int main(void){
    int N,M;
    cin>>N>>M;
    string name;
    map<string,int> dued;
    vector<string> duedbo;
    for(int i = 0;i < N;i++){
        cin>>name;
        dued[name]++;
    }
    for(int i = 0;i < M;i++){
        cin>>name;
        if(dued[name] != 0){
            duedbo.push_back(name);
        }
    }
    stable_sort(duedbo.begin(),duedbo.end());
    cout<<duedbo.size()<<endl;
    for(int i = 0;i < duedbo.size();i++){
        cout<<duedbo[i]<<endl;
    }
}