#include<iostream>
#include<vector>

using namespace std;

int main(void){
    int n,m,a,result = 1,num = 0;
    cin>>n>>m;
    vector<int> seat(n+1,1);
    seat[1] = 1;
    seat[2] = 2;
    for(int i = 3;i < n+1;i++){
        seat[i] = seat[i-1] + seat[i-2];
    }
    for(int i = 0;i < m;i++){
        cin>>a;
        result*=seat[a-num-1];
        num = a;
    }
    cout<<result*seat[n-num];
    return 0;
}