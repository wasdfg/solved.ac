#include<iostream>
#include<string>

using namespace std;

int palindrome(int left,int right,string s,bool removeone){
    while(left < right){
        if(s[left] != s[right]){
            if(removeone == false){
                if(palindrome(left,right-1,s,1) == 0 || palindrome(left+1,right,s,1) == 0){
                    return 1;
                }
            }
            return 2;
        }
        left++;
        right--;
    }
    return 0;
}

int main(void){
    int n;
    string s;
    cin>>n;
    for(int i = 0;i < n;i++){
        cin>>s;
        cout<<palindrome(0,s.length()-1,s,0)<<endl;
    }
    return 0;
}