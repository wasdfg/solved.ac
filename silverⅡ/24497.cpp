#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<int> graph[100001];
vector<bool> visited(100001,false);
int nextvertex[100001];
int nextvalue = 0;

void DFS(int vertex){
    if(visited[vertex] == true)
        return ;
    visited[vertex] = true;
    nextvalue+=1;
    nextvertex[vertex] = nextvalue;
    for(int i = 0;i < graph[vertex].size();i++){
            DFS(graph[vertex][i]);
    }
}

int main(void){
    int n,m,r,start,end;
    scanf("%d %d %d",&n,&m,&r);
    nextvertex[r] = 1;
    for(int i = 1;i <= m;i++){
        scanf("%d %d",&start,&end);
        graph[start].push_back(end);
        graph[end].push_back(start);
    }
    for(int i = 1;i <= n;i++){
        sort(graph[i].begin(),graph[i].end());
    }
    DFS(r);
    for(int i = 1;i <= n;i++){
        printf("%d\n",nextvertex[i]);
    }
}