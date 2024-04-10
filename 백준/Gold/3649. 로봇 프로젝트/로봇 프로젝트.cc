#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void){
    int x,n,left,right;
    vector<int> robo;
    while(cin>>x){
        int l1 = 0,l2 = 0;
        cin>>n;
        x*=10000000;
        robo.assign(n,0);
        for(int i = 0;i < n;i++){
            cin>>robo[i];
        }
        sort(robo.begin(),robo.end());
        left = 0;
        right = n-1;
        bool check = false; 
        while(left < right){
            if(robo[left]+robo[right] == x){
                l1 = robo[left];
                l2 = robo[right];
                check =true;
                break;
            }
            else if(robo[left]+robo[right] > x){
                right--;
            }
            else{
                left++;
            }
        }
        if(check == false){
            cout<<"danger\n";
        }
        else{
            cout<<"yes "<<l1<<" "<<l2<<endl;
        }
    }
    return 0;
}