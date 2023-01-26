#include<iostream>

using namespace std;
long long ccw(long long x1,long long y1,long long x2,long long y2,long long x3,long long y3){
    if(x1*y2 + x2*y3 + x3*y1 - x2*y1 - x3*y2 -x1*y3 > 0)
        return 1;
    else if(x1*y2 + x2*y3 + x3*y1 - x2*y1 - x3*y2 -x1*y3 < 0)
        return -1;
    else
        return 0;
}

int main(void){
    long long x1,y1,x2,y2,x3,y3,x4,y4;
    cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
    if(((ccw(x1,y1,x2,y2,x3,y3)*ccw(x1,y1,x2,y2,x4,y4))<= 0) && ((ccw(x3,y3,x4,y4,x1,y1)*ccw(x3,y3,x4,y4,x2,y2)) <= 0)){
        cout<<"1"<<endl;
    }
    else   
        cout<<"0"<<endl;
}