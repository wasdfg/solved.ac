#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void){
    int n,start = 0,end,count = 0;
    cin>>n;
    vector<int> good(n,0);
    for(int i = 0;i < n;i++){
        cin>>good[i];
    }
    sort(good.begin(),good.end());
    for(int i = 0;i < n;i++){
        start = 0;
        end = n-1;
        while(start < end){
            if(good[start]+good[end] == good[i]){
                if(start != i && end != i){
                    count++;
                    break;
                }
                else if(start == i){
                    start++;
                }
                else if(end == i){
                    end--;
                }
            }
            else if(good[start]+good[end] > good[i]){
                end--;
            }
            else if(good[start]+good[end] < good[i]){
                start++;
            }
        }
    }
    cout<<count;
    return 0;
}