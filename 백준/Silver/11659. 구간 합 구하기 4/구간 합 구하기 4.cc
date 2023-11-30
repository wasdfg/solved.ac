#include<iostream>
#include<vector>

using namespace std;

int main(void){
    int N,M,allsum = 0;
    int i,j;
    int x;
    vector<int> num;
    //cin>>N>>M;
    scanf("%d %d",&N,&M);
    num.push_back(0);
    for(int a = 0;a < N;a++){
        scanf("%d",&x);
        allsum+=x;
        num.push_back(allsum);
    }
    for(int a = 0;a < M;a++){
        //cin>>i>>j;
        scanf("%d %d",&i,&j);
        printf("%d\n",num[j]-num[i-1]);
    }
}