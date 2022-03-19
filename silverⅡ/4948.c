#include<stdio.h>
int main(void){
	int a = 1,count;
	int prime[246914] = {-1,-1,0,};
     for(int i = 2;i * i <= 246912;i++){
     for(int j = i;j <= 246912;j+=i){
        if(j == i)
		continue;
	else{
	    prime[j] = -1;
	}
     }
     }
  while(1){
     scanf("%d",&a);
     if(a == 0)
	     break;
     count = 0;
     for(int i = a+1; i <= 2*a;i++){
         if(prime[i] == 0){
		 count++;
	 }
     }
     printf("%d\n",count);
  }
}
