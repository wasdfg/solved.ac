#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(void){
    int n,front = 0,back = -1,num;
    char cmd[6];
    scanf("%d",&n);
    int *arr = (int*)malloc(sizeof(int)*(n+1));
    memset(arr,-1,n+1);
    for(int i = 0;i < n;i++){
        scanf("%s",cmd);
        if(strcmp("push",cmd) == 0){
            scanf("%d",&num);
            arr[back+1] = num;
            back++;
        }
        if(strcmp("pop",cmd) == 0){
            if(arr[front] == -1)
                printf("-1\n");
            else{
                printf("%d\n",arr[front]);
                arr[front] = -1;
                front++;
            }
        }
        if(strcmp("size",cmd) == 0){
            if(arr[front] == -1)
                printf("0\n");
            else
                printf("%d\n",back-front+1);
        }
        if(strcmp("empty",cmd) == 0){
            if(arr[front] == -1)
                printf("1\n");
            else
                printf("0\n");
        }
        if(strcmp("front",cmd) == 0){
            if(arr[front] == -1)
                printf("-1\n");
            else
                printf("%d\n",arr[front]);
        }
        if(strcmp("back",cmd) == 0){
            if(arr[front] == -1)
                printf("-1\n");
            else
                printf("%d\n",arr[back]);
        }
        memset(cmd,0,6);
    }
    free(arr);
}