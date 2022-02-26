#include<stdio.h>
#include<math.h>
typedef unsigned long long ull;
ull check(ull a,ull b){
	if(b == 0)
		return a;
	else
		return check(b,a % b);
}
int main(void){
  ull gcd,lcm,min = 100000001,tmp,tmp1,tmp2,save;
  scanf("%llu %llu",&gcd,&lcm);
  for(ull i = 1;i <= sqrt(lcm/gcd);i++){
	  if(lcm/gcd % i == 0){
		 tmp1 = i * gcd;
		 tmp2 = lcm/i;
		 tmp = tmp1 + tmp2;
		 if(tmp <= min && check(tmp1,tmp2) == gcd){
			 min = tmp;
			 save = i;
		 }
	  }
  }
  printf("%llu %llu\n",gcd * save,lcm / save);
}
