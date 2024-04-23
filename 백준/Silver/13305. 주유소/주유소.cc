#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void){
    long long n,rest = 0,result = 0,now = 0;
    cin>>n;
    vector<long long> dist(n-1,0);
    vector<long long> oil(n,0);
    for(int i = 0;i < n-1;i++){
        cin>>dist[i];
    }
    for(int i = 0;i < n;i++){
        cin>>oil[i];
    }
    rest = 10000000001;
    for(int i = 0;i < n-1;i++){
        if(oil[i] < rest){
            rest = oil[i];
        }
        result += rest*dist[i]; 
    }
    cout<<result;
    return 0;
}