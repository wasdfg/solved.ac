#include<iostream>
#include<vector>
#include<string>

using namespace std;

string a;

int pal(int start,int end,bool usa){
    while(start < end){
        if(a[start] != a[end]){
            if(usa){
                if(pal(start+1, end, 0) == 0 || pal(start, end-1, 0) == 0){
                    return 1;
                } 
            }
            return 2;
        }
        start++,end--;
    }
    return 0;
}

int main(void){
    int n,result;
    cin>>n;
    for(int i = 0;i < n;i++){
        cin>>a;
        cout<<pal(0,a.length()-1,1)<<endl;
    }
    return 0;
}