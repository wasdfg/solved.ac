#include<iostream>
#include<vector>

using namespace std;

int main(void){
    int n,m,start = 1,end = 0,count,left,result;
    cin>>n>>m;
    vector<int> money(n,0);
    for(int i = 0;i < n;i++){
        cin>>money[i];
        end+=money[i];
    }
    while(start <= end){
        count = 1;
        bool cant = false;
        int mid = (start+end)/2;
        left = mid;
        for(int i = 0;i < n;i++){
            if(money[i] > mid){
                cant = true;
                break;
            }
            if(left < money[i]){
                count++;
                left = mid;
            }
            left-=money[i];
        }
        if(cant || count > m){
            start = mid+1;
        }
        else{
            result = mid;
            end = mid-1;
        }
    }
    cout<<result;
    return 0;
}