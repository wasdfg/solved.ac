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
        visited[a] = 1;
        while(!q.empty()){
            int now = q.front().first;
            string cam = q.front().second;
            q.pop();
            if(now == b){
                cout<<cam<<endl;
                break;
            }
            int d = now * 2 % 10000;
            if(visited[d] == 0){
                q.push({d,cam+'D'});
                visited[d] = 1;
            }
            int s = now-1 >= 0?now-1:9999;
            if(visited[s] == 0){
                q.push({s,cam+'S'});
                visited[s] = 1;
            }
            int l = now % 1000 * 10 + now / 1000;
            if(visited[l] == 0){
                q.push({l,cam+'L'});
                visited[l] = 1;
            }
            int r = now % 10 * 1000 + now / 10;
            if(visited[r] == 0){
                q.push({r,cam+'R'});
                visited[r] = 1;
            }
        }
    }
    return 0;
}