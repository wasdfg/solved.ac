#include<stdio.h>
#include<math.h>
int main(void){
  int che[10002] = {-1,-1,0};
  int a,b,gap,mgap;
  scanf("%d",&a);
  for(int i = 2;i < 101;i++){
     for(int j = i;j < 10001;j+=i){
       if(j == i)
	     continue;
       else{
          che[j] = -1;
       }
     }
  }
  for(int i = 0;i < a;i++){
	  scanf("%d",&b);
	  mgap = 10000;
   for(int j = 2;j <= b/2;j++){
     if(che[j] == 0 && che[b - j] == 0){
       gap = b - j * 2;
     if(gap < mgap){
	    mgap = gap;
     }
     }
   }
  printf("%d %d\n",(b - mgap) / 2,(b + mgap) / 2);
  }
}
