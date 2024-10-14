#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void){
    int x,n,left,right;
    vector<int> robo;
    while(cin>>x){
        int l1 = 0,l2 = 0;
        x*=10000000;
        cin>>n;
        robo.assign(n,0);
        for(int i = 0;i < n;i++){
            cin>>robo[i];
        }
        sort(robo.begin(),robo.end());
        left = 0;
        right = n-1;
        while(left < right){
            if(robo[left]+robo[right] == x){
                if(abs(l2-l1) <= abs(robo[right]-robo[left])){
                    l2 = robo[right];
                    l1 = robo[left];
                }
            }
            if(robo[left]+robo[right] >= x){
                right--;
            }
            else{
                left++;
            }
        }
        if(l1 == 0 && l2 == 0){
            cout<<"danger\n";
        }
        else{
            cout<<"yes "<<l1<<" "<<l2<<endl;
        }
    }
    return 0;
}