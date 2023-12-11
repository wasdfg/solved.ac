#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<pair<int,int>> drive;
vector<bool> visited;
int N,homx,homy,cox,coy,x,y,minlen,sum;

int dfs(int sum,int visit,int a,int b){
    if(sum > minlen)
        return 0;
    if(visit == N){
        int t = abs(homx - a) + abs(homy - b);
        if(sum + t < minlen)
            minlen = sum + t;
        return 0;    
    }
    for(int i = 0;i < N;i++){
        if(visited[i] == false){
            visited[i] = true;
            dfs(sum + abs(a - drive[i].first) + abs(b - drive[i].second),visit + 1,drive[i].first,drive[i].second);
            visited[i] = false;
        }
    }
    return 0;
}

int main(void){
    int tcase;
    cin>>tcase;
    for(int i = 1;i <= tcase;i++){
        minlen = 999999999;
        cin>>N;
        visited.resize(N,false);
        cin>>cox>>coy;
        cin>>homx>>homy;
        for(int j = 0;j < N;j++){
            cin>>x>>y;
            drive.push_back(make_pair(x,y));
        }
        dfs(0,0,cox,coy);
        cout<<"#"<<i<<" "<<minlen<<endl;
        drive.clear();
        vector<pair<int,int>>().swap(drive);
    }
    return 0;
}