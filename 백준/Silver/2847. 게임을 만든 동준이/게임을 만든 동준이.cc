#include<iostream>
#include<vector>

using namespace std;

int main(void){
    int n,count = 0;
    cin>>n;
    vector<int> game(n,0);
    for(int i = 0;i < n;i++){
        cin>>game[i];
    }
    for(int i = n-1;i >= 1;i--){
        if(game[i] <= game[i-1]){
            count+=(game[i-1]-game[i]+1);
            game[i-1] = game[i]-1;
        }
    }
    cout<<count;
    return 0;
}