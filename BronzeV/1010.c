#include<stdio.h>
int main(void){
int a;
int n,m;
int x;
scanf("%d",&a);
for(int i =0;i < a;i++){
scanf("%d %d",&n,&m);
x = m;
unsigned long long bunmo = 1,bunja = 1;
if(n > m/2){
	for(int j = 0; j < m-n;j++){
	    bunmo *= x;
	    x--;
	}
	for(int k = 1; k <= m-n;k++){
	    bunja *= k;
	}
}
else{
	for(int j = 0; j < n;j++){
            bunmo *= x;
            x--;
        }
        for(int k = 1; k <= n;k++){
            bunja *= k;
        }
}
printf("%llu\n",bunmo / bunja);
}
}
