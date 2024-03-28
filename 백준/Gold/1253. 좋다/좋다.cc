#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void){
    int n,start,end,count = 0,check;
    cin>>n;
    vector<int> good(n,0);
    for(int i = 0;i < n;i++){
        cin>>good[i];
    }
    sort(good.begin(),good.end());
    for(int i = 0;i < n;i++){
        start = 0;
        end = n-1;
        check = good[i];
        while(start < end){
            if(good[start]+good[end] > check){
                end--;
            }
            else if(good[start]+good[end] < check){
                start++;
            }
            else{
                if(start == i){
                    start++;
                }
                else if(end == i){
                    end--;
                }
                else{
                    count++;
                    break;
                }
            }
        }
    }
    cout<<count;
    return 0;
}