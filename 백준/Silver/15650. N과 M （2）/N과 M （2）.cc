#include<iostream>
#include<vector>

using namespace std;

vector<int> num;
vector<bool> visited;
int N,M,count = 0;

void seq(int a){
    if(a == M){
        for(int i = 0;i < num.size();i++){
            cout<<num[i]<<" ";
        }
        cout<<"\n";
    }
    for(int i = 0;i < N;i++){
        if(visited[i] == 0 && (a == 0 || (num.back() < i+1))){
            num.push_back(i+1);
            visited[i] = true;
            seq(a+1);
            num.pop_back();
            visited[i] = false;
        }
    }

}

int main(void){
    cin>>N>>M;
    visited.assign(N,0);
    seq(0);
    return 0;
}