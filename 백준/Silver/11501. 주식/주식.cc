#include<iostream>
#include<vector>

using namespace std;

int main(void){
    long long T,N,num,earn,check;
    vector<long long> stock;
    cin>>T;
    for(long long i = 0;i < T;i++){
        earn = 0;
        check = 0;
        cin>>N;
        for(long long j = 0;j < N;j++){
            cin>>num;
            stock.push_back(num);
        }
        for(long long j = N-1;j >= 0;j--){
            if(stock[j] > check){
                check = stock[j];
            }
            else{
                earn += (check - stock[j]);
            }
        }
        cout<<earn<<endl;
        stock.clear();
    }
    return 0;
}