#include<stdio.h>
int main(void){
 int a,b,n,tmp;
 int gcd,lcm;
 scanf("%d %d",&a,&b);
 if(a < b){
   tmp = a;
   a = b;
   b = tmp;
 }
 lcm = a * b;
  while(b!=0){
        n = a%b;
        a = b;
        b = n;
  }
  gcd = a;
  lcm /= gcd;
 printf("%d\n%d\n",gcd,lcm);
}
