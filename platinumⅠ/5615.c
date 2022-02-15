#include<stdio.h>
typedef unsigned long long ull;
int check[3] = {2,7,61};
ull power(ull x,ull y,ull mod){
	ull res = 1;
	x %= mod;
	while(y){
		if(y % 2)
			res = (res * x) % mod;
		y /= 2;
		x = (x*x) % mod;
	}
	return res;
}
ull miller(ull area,ull a){
	ull k = area-1;
	while(1){
		 ull temp = power(a,k,area);
		if(temp == area-1)
			return 1;
		if(k % 2){
		       if(temp == 1)
			       return 1;
		       else
			       return 0;
		}
		k /= 2;
	}
}
int main(void){
	ull a;
	ull area;
	int num = 0,b,count;
	scanf("%llu",&a);
	for(int i = 0;i < a;i++){
		scanf("%llu",&area);
		count = 0;
		b = 0;
		while(b < 3){
		if(area*2+1 == check[b]){
		   count = 3;
		   break;
		}
		if(miller(area * 2 + 1,check[b]) != 0){
		count++;
		}
		b++;
		}
		if(count == 3){
			num++;
		}
	}
	printf("%d\n",num);
}
