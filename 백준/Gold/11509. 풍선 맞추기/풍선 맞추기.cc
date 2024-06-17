#include<iostream>
#include<vector>

using namespace std;

int main(void){
    int n,x,result = 0;
    cin>>n;
    vector<int> ball(1000001,0);
    for(int i = 0;i < n;i++){
        cin>>x;
        if(ball[x+1] > 0){
            ball[x+1]--;
            ball[x]++;
        }
        else{
            ball[x]++;
            result++;
        }
    }
    cout<<result;
    return 0;
}