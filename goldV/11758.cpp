#include<iostream>

using namespace std;

int main(void){
    double x1,y1,x2,y2,x3,y3;
    cin>>x1>>y1>>x2>>y2>>x3>>y3;
    if((x2*y3-y1*x2-x1*y3-y2*x3+x1*y2+y1*x3) > 0){
        cout<<"1"<<endl;
    }
    else if((x2*y3-y1*x2-x1*y3-y2*x3+x1*y2+y1*x3) < 0){
        cout<<"-1"<<endl;
    }
    else
        cout<<"0"<<endl;
}