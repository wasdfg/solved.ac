#include<stdio.h>
#include<stdlib.h>
int main(void){
 int a,b,sum;	
 scanf("%d %d",&a,&b);
 for(int i = 1;i < 100000;i++){
  for(int j = 1;j < 100000;j++){
	 if(j < i)
		 continue;
	 else{
	      int c = i,d = j;
	      for(int k = 2;k < a;k++){
	          sum = c + d;
		  c = d;
		  d = sum;
		  if(sum > b)
		   break;
	      }
	      if(sum == b){
	      printf("%d\n%d\n",i,j);
	      exit(0);
	      }
	    }
	 }
  }
 }
