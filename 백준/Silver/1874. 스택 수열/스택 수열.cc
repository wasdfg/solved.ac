#include<iostream>
#include<stack>
#include<vector>

using namespace std;

int main(void){
    int n,num,now = 1;
    bool check = 1;
    cin>>n;
    stack<int> number;
    vector<char> answer;
    number.push(0);
    for(int i = 0;i < n;i++){
        cin>>num;
        while(num > number.top()){
            number.push(now);
            now++;
            answer.push_back('+');
        }
        if(num == number.top()){
            number.pop();
            answer.push_back('-');
        }
        else{
            check = 0;
        }
    }
    if(!check){
        cout<<"NO";
    }
    else{
        for(int i = 0;i < answer.size();i++){
            cout<<answer[i]<<"\n";
        }
    }
    return 0;
}