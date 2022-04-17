#include<stdio.h>
int main(void){
  int n;
  scanf("%d",&n);
  if(n % 2 == 0)         //2개나 4개를 남기면 필승이다 2개면 자신턴에 3,5가 남아있어야하고 4개면 5,7이 남아있어야한다.
	  printf("CY\n");//베스킨라빈스31 게임을 생각하면 된다.
  else
	  printf("SK\n");
}
