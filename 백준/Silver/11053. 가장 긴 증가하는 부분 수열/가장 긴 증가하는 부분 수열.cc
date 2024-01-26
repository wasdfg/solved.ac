#include<iostream>
#include<vector>

using namespace std;

int main(void){
    int N,num;
    cin>>N;
    vector<int> A;
    vector<int> order;
    order.push_back(0);
    A.push_back(0);
    for(int i = 1;i < N+1;i++){
        cin>>num;
        if(num > A.back()){
            A.push_back(num);
            order.push_back(A.size()-1);
        }
        else{
            for(int j = 1;j < A.size();j++){
                if(num == A[j]){
                    order.push_back(j);
                    break;
                }
                else if(num < A[j]){
                    A[j] = num;
                    order.push_back(j);
                    break;
                }
            }
        }
    }
    int maxi = 0;
    for(int i = 0;i < order.size();i++){
        if(maxi < order[i]){
            maxi = order[i];
        }
    }
    cout<<maxi;
    return 0;
}