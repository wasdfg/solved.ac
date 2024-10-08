#include<iostream>

using namespace std;

void dnq(int x,int y,int len){
    if(len == 1){
        cout<<"*";
    }
    else if((x / (len/3)) % 3 == 1 && (y / (len/3)) % 3 == 1){
        cout<<" ";
    }
    else{
        dnq(x,y,len/3);
    }
}

int main(void){
    int n;
    cin>>n;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            dnq(i,j,n);
        }
        cout<<"\n";
    }
    return 0;
}