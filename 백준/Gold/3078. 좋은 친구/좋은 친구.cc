#include<iostream>
#include<vector>
#include<queue>
#include<string>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n,k,count = 0,check;
    string name;
    vector<int> len(20,0);
    queue<int> q;
    cin>>n>>k;
    for(int i = 0;i < n;i++){
        cin>>name;
        check = name.length();
        count+= len[check];
        if(q.size() >= k){
            len[q.front()]--;
            q.pop();
        }
        len[check]++;
        q.push(check);
    }
    cout<<count;
    return 0;
}