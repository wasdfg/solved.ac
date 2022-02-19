#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(void){
 int a,top = -1,data,front = 0;
 char commend[6];
 scanf("%d%*c",&a);
 int *queue = (int*)malloc((2000001)*sizeof(int));
 memset(queue,-1,2000001*sizeof(int));
 for(int i = 0; i < a; i++){
    scanf("%s",commend);
    if(strcmp(commend,"push") == 0){
	    scanf("%d\n",&data);
	    top++;
	    queue[top] = data;
    }
    if(strcmp(commend,"pop") == 0){
	    if(queue[front] != -1){
	    printf("%d\n",queue[front]);
	    queue[front] = -1;
	    front++;
	    }
	    else{
		    printf("%d\n",-1);
	    }
    }
    if(strcmp(commend,"size") == 0){
	    if(top != -1)
	    printf("%d\n",top-front+1);
	    else
		    printf("%d\n",0);
    }
    if(strcmp(commend,"empty") == 0){
	    if(queue[front] == -1)
            printf("%d\n",1);
	    else
		    printf("%d\n",0);
    }
    if(strcmp(commend,"front") == 0){
	    if(queue[front] != -1)
	    printf("%d\n",queue[front]);
	    else
		    printf("%d\n",-1);
    }
    if(strcmp(commend,"back") == 0){
    	if(top != -1)
		printf("%d\n",queue[top]);
	else
		printf("-1\n");
    }
    memset(commend,0,sizeof(char)*6);
 }
 free(queue);
}
