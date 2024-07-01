#include <string>
#include <vector>
#include<algorithm>

using namespace std;

bool cmp(vector<int> a,vector<int> b){
    return a[1] < b[1];
}

int solution(vector<vector<int>> targets) {
    int answer = 0,now = 0;
    sort(targets.begin(),targets.end(),cmp);
    for(int i = 0;i < targets.size();i++){
        if(now <= targets[i][0]){
            answer++;
            now = targets[i][1];
        }
    }
    return answer;
}