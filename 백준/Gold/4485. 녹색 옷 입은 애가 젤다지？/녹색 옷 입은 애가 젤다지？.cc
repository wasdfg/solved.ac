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
    while(1){
        cin>> n;
        if(n == 0)
            break;
        vector<vector<int>> daijk(n,vector<int>(n,1200));
        vector<vector<int>> zelda(n,vector<int>(n,0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                cin>>zelda[i][j];
            }
        }
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        daijk[0][0] = zelda[0][0];
        pq.push({daijk[0][0],{0,0}});
        while(!pq.empty()){
            int cost = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();
            if(x == n-1 && y == n-1)
                break;
            for(int i = 0;i < 4;i++){
                if(x+dx[i] >= 0 && x+dx[i] < n && y+dy[i] >= 0 && y+dy[i] < n){
                    int ncost = zelda[x+dx[i]][y+dy[i]];
                    if(cost+ncost < daijk[x+dx[i]][y+dy[i]]){
                        daijk[x+dx[i]][y+dy[i]] = cost+ncost;
                        pq.push({cost+ncost,{x+dx[i],y+dy[i]}});
                    }
                }
            }
        }
        cout<<"Problem "<<a<<": "<<daijk[n-1][n-1]<<"\n";
        a++;
    }
    return 0;
}