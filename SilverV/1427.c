#include<stdio.h>
#include<string.h>
int main(void){
	int num;
	int a[10];
	memset(a,0,10*sizeof(int));
	scanf("%d",&num);
	while(num > 0){
		if(num % 10 != 0){
			a[(num%10)]+=1;
		}
		else
			a[0]+=1;
		num /= 10;
	}
	for(int i = 9;i >= 0; i--){
		if(a[i] != 0){
			for(int j = 0;j < a[i]; j++){
				printf("%d",i);
			}
		}
		else
			continue;
	}
	printf("\n");
}
