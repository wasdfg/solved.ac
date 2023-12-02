#include<iostream>
#include<algorithm>

using namespace std;

int main(void){
    int N;
    cin>>N;
    int color[N][3] = {{0,},};
    for(int i = 0;i < N;i++){
        cin>>color[i][0]>>color[i][1]>>color[i][2];
    }
    for(int i = 0;i <= N-1;i++){
        color[i+1][0] += min(color[i][1],color[i][2]);
        color[i+1][1] += min(color[i][0],color[i][2]);
        color[i+1][2] += min(color[i][0],color[i][1]);
    }
    cout<<min({color[N-1][0],color[N-1][1],color[N-1][2]})<<endl;
}