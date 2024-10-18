#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>

using namespace std;

int main(void){
    long double g;
    vector<long double> weight;
    cin>>g;
    for(long double i = 1.0;i*i <= g;i+=(long double)1.0){
        if(g - ((long double)((int)g / i) * i) == (long double)0.0){
            long double x = g / i;
            long double y = i;
            long double a = (x + y) / (long double) 2.0;
            if(a - ((long double)((int)a / 1.0) * (long double)1.0) == (long double)0.0 && x != y){
                weight.push_back(a);
            }
        }
    }
    if(weight.empty()){
        cout<<"-1";
    }
    else{
        sort(weight.begin(),weight.end());
        for(int i = 0;i < weight.size();i++){
            cout<<(int)weight[i]<<endl;
        }
    }
    return 0;
}