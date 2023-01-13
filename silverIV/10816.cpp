#include<cstdio>
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;


bool compare(int a,int b){
        return a < b;
}

int main(){
    int n,m,checkcard;
    scanf("%d",&n);
    vector<int> havecard(n);
    for(int i = 0;i < n;i++){
        scanf("%d",&havecard[i]);
    }
    sort(havecard.begin(),havecard.end(),compare);
    scanf("%d",&m);
    for(int i = 0;i < m;i++){
        scanf("%d",&checkcard);
        printf("%d ",std::upper_bound(havecard.begin(),havecard.end(),checkcard)-std::lower_bound(havecard.begin(),havecard.end(),checkcard));
    }
}