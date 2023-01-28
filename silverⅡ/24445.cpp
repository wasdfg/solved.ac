#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

vector<int> graph[100001];
vector<bool> visited(100001,false);
queue<int> vertex;
int nextvertex[100001];
int nextvalue = 0;

void BFS(int value,int n){
    visited[value] = true;
    vertex.push(value);
    while(!vertex.empty()){
        int current = vertex.front();
        vertex.pop();
        nextvalue++;
        nextvertex[current] = nextvalue;
        for(int i=0;i<graph[current].size();i++){
        int next = graph[current][i];

        if(!visited[next]){
        visited[next] = true;
        vertex.push(next);
        }
    }
    }
}

int main(void){
    int n,m,r,start,end;
    scanf("%d %d %d",&n,&m,&r);
    for(int i = 1;i <= m;i++){
        scanf("%d %d",&start,&end);
        graph[start].push_back(end);
        graph[end].push_back(start);
    }
    for(int i = 1;i <= n;i++){
        sort(graph[i].begin(),graph[i].end(),greater<>());
    }
    BFS(r,n);
    for(int i = 1;i <= n;i++){
        printf("%d\n",nextvertex[i]);
    }
}