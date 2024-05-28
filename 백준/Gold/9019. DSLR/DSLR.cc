#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(void){
    int l,a,b;
    cin>>l;
    for(int i = 0;i < l;i++){
        vector<bool> visited(10000,0);    
        cin>>a>>b;
        queue<pair<int,string>> q;
        q.push({a,""});
        visited[a] = true;
        while(!q.empty()){
            int now = q.front().first;
            string dslr = q.front().second;
            q.pop();
            if(now == b){
                cout<<dslr<<endl;
                break;
            }
            int d = now * 2 % 10000;
            if(!visited[d]){
                visited[d] = 1;
                q.push({d,dslr+"D"});
            }
            int s = now == 0?9999:now-1;
            if(!visited[s]){
                visited[s] = 1;
                q.push({s,dslr+"S"});
            }
            int l = (now % 1000)*10+(now/1000);
            if(!visited[l]){
                visited[l] = 1;
                q.push({l,dslr+"L"});
            }
            int r = (now / 10)+((now % 10) * 1000);
            if(!visited[r]){
                visited[r] = 1;
                q.push({r,dslr+"R"});
            }
        }
    }
    return 0;
}