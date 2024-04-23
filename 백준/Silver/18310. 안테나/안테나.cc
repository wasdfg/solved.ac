#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void){
    int n;
    cin>>n;
    vector<int> home(n,0);
    for(int i = 0;i < n;i++){
        cin>>home[i];
    }
    sort(home.begin(),home.end());
    if(n % 2 == 0){
        cout<<home[n/2-1];
    }
    else{
        cout<<home[n/2];
    }
    return 0;
}