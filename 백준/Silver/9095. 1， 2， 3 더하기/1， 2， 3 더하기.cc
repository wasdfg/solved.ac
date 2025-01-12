#include<iostream>
#include<vector>

using namespace std;

int main(void){
    int t,n;
    cin>>t;
    vector<int> ott(11,0);
    ott[1] = 1;
    ott[2] = 2;
    ott[3] = 4;
    for(int i = 4;i < 11;i++){
        ott[i] = ott[i-1]+ott[i-2]+ott[i-3];
    }
    for(int i = 0;i < t;i++){
        cin>>n;
        cout<<ott[n]<<"\n";
    }
    return 0;
}