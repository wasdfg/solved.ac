#include<stdio.h>
int gcd(int a,int b){
    if(b == 0)
	    return a;
    else{
       if(a < b){
        int tmp = a;
	a = b;
	b = tmp;
       }
       return gcd(b, a%b);
    }
}
int main(void){
   int za1,za2,mo1,mo2;
   int za,mo;
   scanf("%d %d",&za1,&mo1);
   scanf("%d %d",&za2,&mo2);
   za = za1* mo2 + za2 * mo1;
   mo = mo1 * mo2;
   int a = gcd(mo,za);
   za /= a;
   mo /= a;
   printf("%d %d\n",za,mo);
}
