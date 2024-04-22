#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void){
    int n,l,count = 0,now = 0,next = 0;
    cin>>n>>l;
    vector<int> tape(n,0);
    for(int i = 0;i < n;i++){
        cin>>tape[i];
    }
    sort(tape.begin(),tape.end());
    while(next < n){
        if(tape[next]-tape[now] <= l-1){
            next++;
        }
        else{
            count++;
            now = next;
        }
    }
    cout<<count+1;
    return 0;
}