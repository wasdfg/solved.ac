#include<iostream>
#include<vector>

using namespace std;

int main(void){
    int n,l,h,len,result = 0,maxpos = 0,maxh = 0;
    cin>>n;
    vector<int> storage(1001,0);
    for(int i = 0;i < n;i++){
        cin>>l>>h;
        storage[l] = h;
        if(maxh < h){
            maxpos = l;
            maxh = h;
        }
    }
    len = 0;
    for(int i = 1;i < maxpos;i++){
        len = max(storage[i],len);
        result+=len;
    }
    len = 0;
    for(int i = 1000;i > maxpos;i--){
        len = max(storage[i],len);
        result+=len;
    }
    cout<<result+maxh;
    return 0;
}