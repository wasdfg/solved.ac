#include<iostream>

using namespace std;

int main(void){
    int n;
    long double sumx = 0,sumy = 0,sum;
    cin>>n;
    long double x[n+1],y[n+1];
    for(int i = 0;i < n;i++){
        cin>>x[i]>>y[i];
    }
    for(int i = 0;i < n-1;i++){
        sumx += (x[i] * y[i+1]);
        sumy += (x[i+1] * y[i]);
    }
    sumx += (x[n-1] * y[0]);
    sumy += (y[n-1] * x[0]);
    sum = (long double)(0.5) * (labs(sumx - sumy));
    cout << fixed;
    cout.precision(1);
    cout<<sum<<endl;
}