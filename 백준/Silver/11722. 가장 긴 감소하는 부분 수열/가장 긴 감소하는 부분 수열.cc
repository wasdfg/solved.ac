#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void){
    int n,num;
    cin>>n;
    vector<int> box;
    vector<int> lis;
    box.push_back(1001);
    lis.push_back(0);
    for(int i = 1;i <= n;i++){
        cin>>num;
        if(num < box.back()){
            box.push_back(num);
            lis.push_back(box.size()-1);
        }
        else{
            for(int j = 1;j <= box.size();j++){
                if(box[j] == num){
                    lis.push_back(j);
                    break;
                }
                else if(box[j] < num){
                    box[j] = num;
                    lis.push_back(j);
                    break;
                }
            }
        }
    }
    cout<<*max_element(lis.begin(),lis.end());
    return 0;
}