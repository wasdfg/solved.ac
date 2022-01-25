#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int gcd(int a,int b){
    if(a != 0 && b != 0){
    if(a > b)
	    return gcd(a%b,b);
    else
	    return gcd(b,a%b);
    }
    return a+b;
}
int main(void){
   int a,n;
   scanf("%d",&a);
   int *rad = (int*)malloc((a+1)*sizeof(int));
   memset(rad,0,(a+1)*sizeof(int));
   for(int i = 0;i < a;i++){
      scanf("%d",&n);
      rad[i] = n;
   }
   int x = rad[0];
   for(int i = 1;i < a; i++){
      printf("%d/%d\n",x/gcd(x,rad[i]),rad[i]/gcd(x,rad[i]));
   }
   free(rad);
}
