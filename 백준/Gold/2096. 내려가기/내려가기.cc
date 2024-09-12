#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void){
    int n,a,b,c,tmp0,tmp1;
    cin>>n;
    vector<int> mindp(3,0);
    vector<int> maxdp(3,0);
    cin>>a>>b>>c;
    mindp[0] = maxdp[0] = a;
    mindp[1] = maxdp[1] = b;
    mindp[2] = maxdp[2] = c;
    for(int i = 1;i < n;i++){
        cin>>a>>b>>c;
        tmp0 = mindp[0];
        tmp1 = mindp[1];
        mindp[0] = a + min(mindp[0],mindp[1]);
        mindp[1] = b + min({tmp0,mindp[1],mindp[2]});
        mindp[2] = c + min(tmp1,mindp[2]);
        tmp0 = maxdp[0];
        tmp1 = maxdp[1];
        maxdp[0] = a + max(maxdp[0],maxdp[1]);
        maxdp[1] = b + max({tmp0,maxdp[1],maxdp[2]});
        maxdp[2] = c + max(tmp1,maxdp[2]);
    }
    cout<<max({maxdp[0],maxdp[1],maxdp[2]})<<" "<<min({mindp[0],mindp[1],mindp[2]});
    return 0;
}