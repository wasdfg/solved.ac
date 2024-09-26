#include<iostream>
#include<vector>

using namespace std;

int main(void){
    long long x,y,left = 0,right = 1000000000,win;
    cin>>x>>y;
    if((y * 100 / x) >= 99){
        cout<<-1;
    }
    else{
        win = y * 100 / x;
        while(left <= right){
            long long mid = (right + left)/2;
            if((y+mid)*100/(x+mid) > win){
                right = mid-1;
            }
            else{
                left = mid+1;
            }
        }
        cout<<left;
    }
    return 0;
}