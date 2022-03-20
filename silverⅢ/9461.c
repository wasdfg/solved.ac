#include<stdio.h>
long long pado(long long *num,int a){
     if(a <= 2)
	     return 1;
     if(num[a] != 0)
	return num[a];
     else{
        return (num[a] = pado(num,a - 2) + pado(num,a-3));
     }
}
int main(void){
   long long num[100] = {1,1,1,0,};
   int a,b;
   scanf("%d",&a);
   for(int i = 0;i < a;i++){
	   scanf("%d",&b);
   printf("%lld\n",pado(num,b-1));
   }
}
