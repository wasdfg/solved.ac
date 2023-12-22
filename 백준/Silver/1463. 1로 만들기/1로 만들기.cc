#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void){
    int N;
    cin>>N;
    vector<int> makeone(N+1,0);
    for(int i = 2;i <= N;i++){
        makeone[i] = makeone[i-1] + 1;
        if(i % 2 == 0){
            makeone[i] = min(makeone[i/2]+1,makeone[i]);
        }
        if(i % 3 == 0){
            makeone[i] = min(makeone[i/3]+1,makeone[i]);
        }
    }
    cout<<makeone[N];
    return 0;
}