#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

int main(void){
    double avg = 0.0;
    int n,x;
    cin>>n;
    if(n != 0){
        vector<int> diff(n,0);
        for(int i = 0;i < n;i++){
            cin>>diff[i];
        }
        sort(diff.begin(),diff.end());
        for(int i = round(n*0.15);i < n-round(n*0.15);i++){
            avg+=diff[i];
        }
        avg/=(n-round(n*0.15)-round(n*0.15));
        cout<<round(avg);
    }
    else{
        cout<<0;
    }
    return 0;
}