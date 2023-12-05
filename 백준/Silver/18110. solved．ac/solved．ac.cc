#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

int main(void){
    int diff;
    double num,cut,avg;
    vector<double> diffi;
    cin>>num;
    if(num == 0){
        cout<<0<<endl;
    }
    else{
        for(int i = 0;i < num;i++){
            cin>>diff;
            diffi.push_back(diff);
        }
        stable_sort(diffi.begin(),diffi.end());
        cut = round(num * 0.15);
        for(int i = cut;i < num - cut;i++){
            avg+=diffi[i];
        }
        avg/=(num-cut-cut);
        avg= round(avg);
        cout<<round(avg)<<endl;
    }
}