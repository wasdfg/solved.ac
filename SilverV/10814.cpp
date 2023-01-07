#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>

using namespace std;
struct online{
    int age;
    char name[101];
};
bool compare(online dic1,online dic2){
        return dic1.age < dic2.age;
}

int main(){
    int n;
    scanf("%d",&n);
    struct online *dic;
    dic = (struct online*)malloc(sizeof(struct online)*(n+1));
    memset(dic,0,sizeof(struct online)*(n+1));
    for(int i = 0;i < n;i++){
        scanf("%d",&dic[i].age);
        scanf("%s",dic[i].name);
    }
    stable_sort(dic,dic+n,compare);
    for(int i = 0;i < n;i++){
        printf("%d %s\n",dic[i].age,dic[i].name);
    }
    free(dic);
}