#include<stdio.h>
int mem0[41] = {1,0,};
int mem1[41] = {0,1,};
int main(void){
  int a,b;
  scanf("%d",&a);
  for(int i = 2; i < 41;i++){
     mem0[i] = mem0[i-1] + mem0[i-2];
     mem1[i] = mem1[i-1] + mem1[i-2];
  }
  for(int i = 0;i < a;i++){
   scanf("%d",&b);
   printf("%d %d\n",mem0[b],mem1[b]);
  }
}
