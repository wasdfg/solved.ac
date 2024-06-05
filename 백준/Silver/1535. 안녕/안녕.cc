#include<iostream>
#include<vector>

using namespace std;

int main(void){
    int n;
    cin>>n;
    vector<int> health(n,0);
    vector<int> happy(n,0);
    vector<int> kn(100,0);
    for(int i = 0;i < n;i++){
        cin>>health[i];
    }
    for(int i = 0;i < n;i++){
        cin>>happy[i];
    }
    for(int i = 0;i < n;i++){
        for(int j = 99;j >= health[i];j--){
            kn[j] = max(kn[j],kn[j-health[i]]+happy[i]);
        }
    }
    cout<<kn[99];
    return 0;
}