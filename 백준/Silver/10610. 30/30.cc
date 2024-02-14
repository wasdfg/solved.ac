#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main(void){
    string N;
    string result = "";
    char c;
    int a = 0;
    vector<int> number(10,0);
    cin>>N;
    for(auto c:N){
        number[c-48]++;
    }
    for(int i = 1;i < 10;i++){
        a += (i *number[i]);
    }
    if(number[0] == 0 || a % 3 != 0){
        cout<<"-1";
    }
    else{
        for(int i = 9;i >= 0;i--){
            for(int j = 0;j < number[i];j++){
                result+=to_string(i);
            }
        }
        cout<<result;
    }
    return 0;
}