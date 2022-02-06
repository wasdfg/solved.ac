#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(void){
 int a,top = -1,data;
 char commend[6];
 scanf("%d%*c",&a);
 int *stack = (int*)malloc((10001)*sizeof(int));
 memset(stack,-1,10001*sizeof(int));
 for(int i = 0; i < a; i++){
    scanf("%s",commend);
    if(strcmp(commend,"push") == 0){
	    scanf("%d\n",&data);
	    top++;
	    stack[top] = data;
    }
    if(strcmp(commend,"pop") == 0){
	    if(top != -1){
	    printf("%d\n",stack[top]);
	    stack[top] = -1;
	    top--;
	    }
	    else{
		    printf("%d\n",-1);
	    }
    }
    if(strcmp(commend,"size") == 0){
	    if(top != -1)
	    printf("%d\n",top+1);
	    else
		    printf("%d\n",0);
    }
    if(strcmp(commend,"empty") == 0){
	    if(top == -1)
            printf("%d\n",1);
	    else
		    printf("%d\n",0);
    }
    if(strcmp(commend,"top") == 0){
	    if(top != -1)
	    printf("%d\n",stack[top]);
	    else
		    printf("%d\n",-1);
    }
    memset(commend,0,sizeof(char)*6);
 }
 free(stack);
}
