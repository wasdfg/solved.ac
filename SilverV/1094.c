#include<stdio.h>
int main(void){
 int a;
 int count = 0;
 scanf("%d",&a);
 while(a > 0){
  if(a%2==1)
	count++;	  
  a = a/2;
 }
 printf("%d\n",count);
}
