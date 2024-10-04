#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);
    string s;
    int q,l,r;
    char a;
    cin>>s>>q;
    vector<vector<int>> word(26,vector<int>(s.length()+1,0));
    for(int i = 0;i < s.length();i++){
        if(i != 0){
            for(int j = 0;j < 26;j++){
                word[j][i]+=word[j][i-1];
            }
        }
        word[s[i]-'a'][i]++;
    }
    for(int i = 0;i < q;i++){
        cin>>a>>l>>r;
        if(l == 0){
            cout<<word[a-'a'][r]<<"\n";
        }
        else{
            cout<<word[a-'a'][r]-word[a-'a'][l-1]<<"\n";
        }
    }
    return 0;
}