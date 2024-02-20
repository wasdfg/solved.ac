#include<iostream>
#include<vector>

using namespace std;

vector<bool> check(1000001,1);

int main(void){
    int n;
    bool notprime = false;
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    check[0] = 0;
    check[1] = 0;
    for(int i = 2;i < 1001;i++){
        for(int j = 2;j * i < 1000001;j++){
            check[i*j] = 0;
        }
    }
    while(1){
        cin>>n;
        if(n == 0){
            break;
        }
        else{
            for(int i = n-1;i >= 2;i--){
                if(check[i] == true && check[n-i] == true){
                    cout<<n<<" = "<<n-i<<" + "<<i<<"\n";
                    break;
                }
            }
            if(notprime == true){
                cout<<"Goldbach's conjecture is wrong.\n";
            }
        }
    }
    return 0;
}