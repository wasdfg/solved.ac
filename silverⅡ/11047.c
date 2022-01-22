#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(void){
 int n,k;
 int num;
 int needcoin = 0;
 int sum;
 scanf("%d %d",&n,&k);
 sum = k;
 int *money = (int*)malloc((n+1) * sizeof(int));
 memset(money,0,(n+1)*sizeof(int));
 for(int i = 0; i < n; i++){
    scanf("%d",&num);
    money[i] = num;
 }
 while(sum > 0){
 for(int i = n-1; i >= 0;i--){
     if(sum / money[i] > 0){
         needcoin += (sum / money[i]);
	 sum %= money[i];
     }
 }
 }
 printf("%d\n",needcoin);
 free(money);
}
