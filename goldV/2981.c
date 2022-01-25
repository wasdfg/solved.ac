#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int gcd(int a,int b){
        if(a!=0 && b!=0){
        if(a > b)
                return gcd(a%b,b);
        else
                return gcd(a,b%a);
        }
        return a+b;
}
int main(void){
        int k,n;
        scanf("%d",&k);
        int *num = (int*)malloc((k+1)*sizeof(int));
        memset(num,0,(k+1)*sizeof(int));
        for(int i = 0;i < k;i++){
                scanf("%d",&n);
                num[i] = n;
        }
        int x = abs(num[1] - num[0]);
        for(int i = 2;i < k; i++){
                x = gcd(x,abs(num[i] - num[i-1]));
        }
	 for(int i=2;i*i<=x;i++){
		 if(x%i==0) 
			 printf("%d ",i);
	 }
    for(int i=sqrt(x-1);i>=1;i--){
	    if(x%i==0) 
		    printf("%d ",x/i);
    }
        printf("\n");
        free(num);
}

