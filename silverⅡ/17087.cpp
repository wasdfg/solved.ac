#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
int gcd(int a,int b){
    if(a < b){
        int tmp = a;
        a = b;
        b = tmp;
    }
    if(b == 0){
        return a;
    }
    else{
        return gcd(a%b,b);
    }
}

int main(void){
    vector<int> diff;
    int n,s,way,min1;
    cin>>n>>s;
    for(int i = 0;i < n;i++){
        cin>>way;
        diff.push_back(abs(s-way));
    }
    stable_sort(diff.begin(),diff.end());
    min1 = diff[0];
    for(int i = 0;i < n;i++){
        min1 = gcd(min1,diff[i]);
    }
    cout<<min1<<endl;
}