#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void){
    int n,s = 0,e,x,y,check = 2100000000;
    cin>>n;
    e = n-1;
    vector<int> liq(n,0);
    for(int i = 0;i < n;i++){
        cin>>liq[i];
    }
    sort(liq.begin(),liq.end());
    while(s < e){
        if(abs(liq[e]+liq[s]) < check){
            x = liq[s];
            y = liq[e];
            check = abs(liq[e]+liq[s]);
        }
        if(liq[e]+liq[s] < 0){
            s++;
        }
        else{
            e--;
        }
    }
    cout<<x<<" "<<y;
    return 0;
}