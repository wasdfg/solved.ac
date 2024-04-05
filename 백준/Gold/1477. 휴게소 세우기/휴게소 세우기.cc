#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void){
    int n,m,l,result,left,right,count;
    cin>>n>>m>>l;
    vector<int> hugeso(n+1,0);
    for(int i = 1;i <= n;i++){
        cin>>hugeso[i];
    }
    hugeso.push_back(l);
    sort(hugeso.begin(),hugeso.end());
    left = 1;
    right = l;
    while(left <= right){
        count = 0;
        int mid = (left+right)/2;
        for(int i = 1;i < hugeso.size();i++){
            count+=(hugeso[i]-hugeso[i-1])/mid;
            if((hugeso[i]-hugeso[i-1]) % mid == 0){
			    count--;
            }
        }
        if(count > m){
            left = mid+1;
        }
        else{
            result = mid;
            right = mid-1;
        }
    }
    cout<<result;
    return 0;
}