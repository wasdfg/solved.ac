#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
    int n,a = 1;
    int dx[4] = {0,0,-1,1};
    int dy[4] = {1,-1,0,0};
    vector<vector<int>> br;
    vector<vector<int>> dist;
    while(1){
        cin>>n;
        if(n == 0){
            return 0;
        }
        else{
            br.assign(n,vector<int>(n,0));
            dist.assign(n,vector<int>(n,987654321));
            for(int i = 0;i < n;i++){
                for(int j = 0;j < n;j++){
                    cin>>br[i][j];
                }
            }
            queue<pair<int,int>> pq;
            pq.push({0,0});
            dist[0][0] = br[0][0];
            while(!pq.empty()){
                int x = pq.front().first;
                int y = pq.front().second;
                pq.pop();
                for(int i = 0;i < 4;i++){
                    if(x+dx[i] >= 0 && x+dx[i] < n && y+dy[i] >= 0 && y+dy[i] < n){
                        if(dist[x+dx[i]][y+dy[i]] > br[x+dx[i]][y+dy[i]]+dist[x][y]){
                            dist[x+dx[i]][y+dy[i]] = br[x+dx[i]][y+dy[i]]+dist[x][y];
                            pq.push({x+dx[i],y+dy[i]});
                        }
                    }
                }
            }
            cout<<"Problem "<<a<<": "<<dist[n-1][n-1]<<endl;
        }
        a++;
    }
    return 0;
}