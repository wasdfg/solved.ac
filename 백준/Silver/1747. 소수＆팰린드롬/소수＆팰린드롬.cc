#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main(void){
    int n;
    vector<bool> prime(1100001,1);
    prime[1] = 0;
    cin>>n;
    for(int i = 2;i*i < 1100001;i++){
        for(int j = 2;j*i < 1100001;j++){
            prime[i*j] = 0;
        }
    }
    for(int i = n;i < 1100001;i++){
        if(prime[i] == 1){
            string s = to_string(i);
            int len = s.length();
            bool check = true;
            for(int j = 0;j < len/2;j++){
                if(s[j] != s[len-j-1]){
                    check = false;
                    break;
                }
            }
            if(check == true){
                cout<<i;
                return 0;
            }
        }
    }
    return 0;
}