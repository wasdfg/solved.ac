#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> point;
vector<int> check;

int main(void){
    int N,num;
    cin>>N;
    for(int i = 0;i < N;i++){
        cin>>num;
        point.push_back(num);
        check.push_back(num);
    }
    stable_sort(point.begin(),point.end());
    point.erase(unique(point.begin(),point.end()),point.end());
    for(int i = 0;i < N;i++){
        cout<< lower_bound(point.begin(),point.end(),check[i])-point.begin()<<" ";
    }
    return 0;
}