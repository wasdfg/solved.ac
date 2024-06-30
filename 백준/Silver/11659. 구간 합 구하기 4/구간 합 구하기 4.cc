#include<iostream>
#include<vector>

using namespace std;

int main(void){
    cin.tie(NULL);
	ios::sync_with_stdio(false);
    int total = 0;
    int n,m,a,b,x;
    vector<int> num(100001,0);
    cin>>n>>m;
    num.push_back(0);
    for(int i = 0;i < n;i++){
        cin>>x;
        total+=x;
        num[i+1] = total;
    }
    for(int i = 0;i < m;i++){
        cin>>a>>b;
        cout<<num[b]-num[a-1]<<"\n";
    }
    return 0;
}