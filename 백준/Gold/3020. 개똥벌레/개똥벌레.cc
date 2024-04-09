#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void){
    int n,h,result = 200001,value = 0;
    cin>>n>>h;
    vector<int> even(n/2,0);
    vector<int> odd(n/2,0);
    for(int i = 0;i < n/2;i++){
        cin>>odd[i]>>even[i];
    }
    sort(odd.begin(),odd.end());
    sort(even.begin(),even.end());
    for(int i = 1;i <= h;i++){
        int check = lower_bound(odd.begin(),odd.end(),i)-odd.begin();
        check+=upper_bound(even.begin(),even.end(),h-i)-even.begin();
        check = n-check;
        if(check == result){
            value++;
        }
        else if(check < result){
            result = check;
            value = 1;
        }
    }
    cout<<result<<" "<<value;
    return 0;
}