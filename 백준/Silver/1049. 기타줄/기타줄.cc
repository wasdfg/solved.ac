#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void){
    int n,m,a,b,result = 0,single = 1000,set = 1000;
    cin>>n>>m;
    for(int i = 0;i < m;i++){
        cin>>a>>b;
        set = min(set,a);
        single = min(single,b);
    }
    cout<<min((n/6+1)*set,min(n/6*set+n%6*single,n*single));
    return 0;
}