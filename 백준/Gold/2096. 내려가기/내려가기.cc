#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void){
    int N,a,b,c,check0 = 0,check2 = 0;
    cin>>N;
    vector<int> mindp(3,0);
    vector<int> maxdp(3,0);
    cin>>mindp[0]>>mindp[1]>>mindp[2];
    maxdp[0] = mindp[0];
    maxdp[1] = mindp[1];
    maxdp[2] = mindp[2];
    for(int i = 1;i < N;i++){
        cin>>a>>b>>c;
        check0 = mindp[0],check2 = mindp[2];
        mindp[0] = min(mindp[0],mindp[1])+a;
        mindp[2] = min(mindp[1],mindp[2])+c;
        mindp[1] = min({check0,mindp[1],check2})+b;
        
        check0 = maxdp[0],check2 = maxdp[2];
        maxdp[0] = max(maxdp[0],maxdp[1])+a;
        maxdp[2] = max(maxdp[1],maxdp[2])+c;
        maxdp[1] = max({check0,maxdp[1],check2})+b;
    }
    
    cout<<max({maxdp[0],maxdp[1],maxdp[2]})<<" "<<min({mindp[0],mindp[1],mindp[2]});
    return 0;
}