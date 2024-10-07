#include<iostream>
#include<cmath>

using namespace std;

int n,r,c;
int result = 0;

void dnq(int x,int y,int pos){
    if(x == r && y == c){
        cout<<result;
        return ;
    }
    else if(r >= x && r < x+pos && c >= y && c < y+pos){
        dnq(x,y,pos/2);
        dnq(x,y+pos/2,pos/2);
        dnq(x+pos/2,y,pos/2);
        dnq(x+pos/2,y+pos/2,pos/2);
    }
    else{
        result+=(pos*pos);
    }
}

int main(void){
    cin>>n>>r>>c;
    dnq(0,0,pow(2,n));
    return 0;
}