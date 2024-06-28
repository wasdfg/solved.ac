#include<iostream>
#include<vector>

using namespace std;

int main(void){
    int n;
    long double sum = 0;
    cin>>n;
    vector<long double> x(n+1,0),y(n+1,0);
    for(int i = 0;i < n;i++){
        cin>>x[i]>>y[i];
    }
    for(int i = 0;i < n-1;i++){
        sum+=((x[i]+x[i+1])*(y[i]-y[i+1]));
    }
    sum+=((x[n-1]+x[0])*(y[n-1]-y[0]));
    sum = abs(sum);
    sum/=2;
    cout<<fixed;
    cout.precision(1);
    cout<<sum;
    return 0;
}