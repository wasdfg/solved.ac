#include<stdio.h>
#include<stdlib.h>
int main(void){
	int *prime;
	prime = (int*)malloc(1000001 * sizeof(int));
	int a,b,count = 0,num;
	scanf("%d %d",&a,&b);
	prime[0] = 0;
	for(int i = 1; i < 1000000;i++){
		prime[i] = i+1;
	}
	for(int i = 2; i <= 1000;i++){
		for(int j =2; j <= 500000;j++){
			if(i*j > 1000000){
				break;
			}
			else{
				prime[(i*j)-1] = 0;
			}
		}
	}
	for(int i = a; i <= b;i++){
		if(prime[i-1] != 0){
			printf("%d\n",prime[i-1]);
		}
	}
	free(prime);
}
