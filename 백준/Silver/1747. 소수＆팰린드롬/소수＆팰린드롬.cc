#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main(void){
    int n;
    vector<int> prime(1100001,1);
    prime[1] = 0;
    cin>>n;
    for(int i = 2;i*i <= 1100000;i++){
        for(int j = 2;j*i <= 1100000;j++){
            prime[i*j] = 0;
        }
    }
    for(int i = n;i <= 1100000;i++){
        if(prime[i] == 1){
            string s = to_string(i);
            bool check = true;
            if(s.length() % 2 == 0){
                for(int j = 0;j < s.length()/2;j++){
                    if(s[j] != s[s.length()-1-j]){
                        check = false;
                        break;
                    }
                }
            }
            else{
                for(int j = 0;j < s.length()/2;j++){
                    if(s[j] != s[s.length()-1-j]){
                        check = false;
                        break;
                    }
                }
            }
            if(check == true){
                cout<<i;
                break;
            }
        }
    }
    return 0;
}