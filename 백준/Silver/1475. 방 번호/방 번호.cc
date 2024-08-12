#include<iostream>
#include<vector>

using namespace std;

int main(void){
    int n,result = 0;
    cin>>n;
    vector<int> ten(10,0);
    while(n > 0){
        ten[n%10]++;
        n/=10;
    }
    for(int i = 0;i < 10;i++){
        if(i == 9 || i == 6){
            continue;
        }
        result = max(result,ten[i]);
    }
    int check = ten[9]+ten[6];
    if(check % 2 == 0){
        check/=2;
    }
    else{
        check = (check+1)/2;
    }
    result = max(result,check);
    cout<<result;
    return 0;
}