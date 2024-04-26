#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main(void){
    int n,m,count = 0;
    string s,result = "";
    cin>>n>>m;
    vector<string> dna(n);
    vector<int> alpha(26,0);
    for(int i = 0;i < n;i++){
        cin>>dna[i];
    }
    sort(dna.begin(),dna.end());
    for(int i = 0;i < m;i++){
        alpha.assign(26,0);
        for(int j = 0;j < n;j++){
            alpha[dna[j][i]-65]++;
        }
        result+=(max_element(alpha.begin(),alpha.end())-alpha.begin()+65);
        int nosum = *max_element(alpha.begin(),alpha.end());
        int sum = 0;
        for(int j = 0;j < 26;j++){
            sum+=alpha[j];
        }
        sum-=nosum;
        count+=sum;
    }
    cout<<result<<endl<<count;
    return 0;
}