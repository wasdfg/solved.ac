#include<iostream>
#include<vector>

using namespace std;

int main(void){
    int n,m,count = 0;
    cin>>n>>m;
    vector<vector<int>> a(n,vector<int>(m,0));
    vector<vector<int>> b(n,vector<int>(m,0));
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            scanf("%1d",&a[i][j]);
        }
    }
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            scanf("%1d",&b[i][j]);
        }
    }
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            if(i > n-3 || j > m-3){
                if(a[i][j] != b[i][j]){
                    cout<<"-1";
                    return 0;
                }
            }
            if(a[i][j] != b[i][j]){
                for(int x = i;x < i+3;x++){
                    for(int y = j;y < j+3;y++){
                        a[x][y] ^= 1;
                    }
                }
                count++;
            }
        }
    }
    cout<<count;
    return 0;
}