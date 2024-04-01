#include<iostream>
#include<vector>

using namespace std;

int main(void){
    int n,m,left = 1,right = 0,mid,count,check,result;
    cin>>n>>m;
    vector<int> money(n,0);
    for(int i = 0;i < n;i++){
        cin>>money[i];
        right+=money[i];
    }
    while(left <= right){
        bool no = 1;
        mid = (left+right) / 2;
        check = mid;
        count = 1;
        for(int i = 0;i < n;i++){
            if(mid < money[i]){
                no = 0;
                break;
            }
            if(check < money[i]){
                check = mid;
                count++;
            }
            check-=money[i];
        }
        if(count > m || no == 0){
            left = mid + 1;
        }
        else{
            result = mid;
            right = mid - 1;
        }
    }
    cout<<result;
    return 0;
}