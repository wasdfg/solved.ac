#include<stdio.h>
#include<string.h>
int main(void){
char a[6];
int num = 0;
int k = 1;
scanf("%s",a);
for(int i = strlen(a) - 1;i >= 0;i--){
	char b = a[i];
	if(b < 58 && b > 47){
	  num += k * (b - 48);
	}
	else
		num+= k * (b - 55);
	k = k * 16;
}
printf("%d\n",num);
}
