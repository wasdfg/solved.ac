#include<iostream>
#include<vector>

using namespace std;

int main(void){
    int n;
    cin>>n;
    vector<int> stone(n+1,0);
    stone[5] = stone[4] = stone[3] = stone[1] = 1;
    for(int i = 6;i < n+1;i++){
        stone[i] = (stone[i-1] == 0 || stone[i-3] == 0 || stone[i-4] == 0) == 1?1:0; 
    }
    if(stone[n] == 1){
        cout<<"SK";
    }
    else{
        cout<<"CY";
    }
    return 0;
}