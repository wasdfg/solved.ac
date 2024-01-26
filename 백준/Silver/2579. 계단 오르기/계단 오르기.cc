#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void){
    int N;
    cin>>N;
    vector<int> makeone(N+1,0);
    vector<int> copy(N+1,0);
    makeone[0] = 0;
    for(int i = 1;i < N+1;i++){
        cin>>makeone[i];
    }
    if(makeone.size() <= 2){
        int x = 0;
        for(int i = 0;i < makeone.size();i++){
            x+=makeone[i];
        }
        cout<<x;
    }
    else{
        copy[0] = 0;
        copy[1] = makeone[1];
        copy[2] = makeone[1]+makeone[2];
        copy[3] = makeone[3]+max(makeone[1],makeone[2]);
        for(int i = 4;i < N+1;i++){
            copy[i] = max(copy[i-2],copy[i-3]+makeone[i-1])+makeone[i];
        }
        cout<<copy[N];
    }
    return 0;
}