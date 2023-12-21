#include<iostream>

using namespace std;

int main(void){
    int T,n;
    cin>>T;
    int ott[12] = {0,1,2,4,0,};
    for(int i = 4;i < 12;i++){
        ott[i] = ott[i-1]+ott[i-2]+ott[i-3];
    }
    for(int i = 0;i < T;i++){
        cin>>n;
        cout<<ott[n]<<endl;
    }
}