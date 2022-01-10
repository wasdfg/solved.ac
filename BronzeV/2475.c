#include<stdio.h>
int main(void){
int a;
int sum = 0;
 for(int i = 0; i < 5; i++){
   scanf("%d",&a);
   sum += a * a;
 } 
 printf("%d\n",sum % 10);
}
