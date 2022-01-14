#include<stdio.h>
#include<stdlib.h>
int main(void){
	int a,k,i;
	int min,max;
  scanf("%d",&a);
  if(a == 1){
  scanf("%d",&k);
  printf("%lld\n",(long long)k*k);
  }
  else{
	int *num = (int*)calloc(a,sizeof(int));  
	for(i = 0; i < a; i++){
	 scanf("%d",&num[i]); 
	}
	min = num[0],max = num[0];
	for(i = 1; i < a; i++){
        if(min > num[i])
		min = num[i];
	}
for(i = 1; i < a; i++){
	if(max < num[i])
		max = num[i];
        }
	printf("%lld\n",(long long)min * max);
	free(num);
  }
}
