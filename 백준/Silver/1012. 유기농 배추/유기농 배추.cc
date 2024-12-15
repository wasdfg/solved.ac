#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(void){
    int t,n,m,k,a,b,count;
    int dx[4] = {0,0,-1,1};
    int dy[4] = {1,-1,0,0};
    cin>>t;
    for(int i = 0;i < t;i++){
        cin>>m>>n>>k;
        count = 0;
        vector<vector<int>> bechu(n,vector<int>(m,0));
        for(int j = 0;j < k;j++){
            cin>>b>>a;
            bechu[a][b] = 1;
        }
        for(int s = 0;s < n;s++){
            for(int t = 0;t < m;t++){
                if(bechu[s][t] == 1){
                    count++;
                    bechu[s][t] = 0;
                    queue<pair<int,int>> togo;
                    togo.push({s,t});
                    while(!togo.empty()){
                        int x = togo.front().first;
                        int y = togo.front().second;
                        togo.pop();
                        for(int u = 0;u < 4;u++){
                            if(x+dx[u] >= 0 && x+dx[u] < n && y+dy[u] >= 0 && y+dy[u] < m && bechu[x+dx[u]][y+dy[u]] == 1){
                                bechu[x+dx[u]][y+dy[u]] = 0;
                                togo.push({x+dx[u],y+dy[u]});
                            } 
                        }
                    }
                }
            }
        }
        cout<<count<<"\n";
    }
    return 0;
}