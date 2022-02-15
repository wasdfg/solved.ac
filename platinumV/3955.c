#include<stdio.h>
long long uc(int i,int j){
	long long r1 = i,r2 = j;
	long long s1 = 1,s2 = 0,t1 = 0,t2 = 1;
	long long s,q,r,t;
	while(r2 > 0){
		q = r1 / r2;
		r = r1 % r2;
		r1 = r2;
		r2 = r;
		s = s1 - q * s2;
		s1 = s2;
		s2 = s;
		t = t1 - q * t2;
		t1 = t2;
		t2 = t;
	}
	r = r1,t = t1,s = s1;
	if(r == 1){
		if(t < 0){
			t += i;
		}
		return t;
	}
	else
		return 0;
}
int main(void){
	int num;
	int a,b;
	scanf("%d",&num);
	for(int i = 0;i < num;i++){
		scanf("%d %d",&a,&b);
		if(a == 1 && b == 1){
			printf("2\n");
			continue;
		}
		else if(a > 1 && b == 1){
		       if(a == 1000000000)
			       printf("IMPOSSIBLE\n");
		       else
			       printf("%d\n",a+1);
		}
		else if(uc(a,b) == 0){
			printf("IMPOSSIBLE\n");
		}
		else
			printf("%lld\n",uc(a,b));
	}
}
