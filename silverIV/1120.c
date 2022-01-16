#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(void){
 char *a = (char*)calloc(51,sizeof(char));
 char *b = (char*)calloc(51,sizeof(char));
 scanf("%s %s",a,b);
 int min = strlen(b);
 for(int i =0; i <= strlen(b)-strlen(a); i++){
	 int diff = 0;
     for(int j = 0; j < strlen(a); j++){
         if(a[j] != b[i+j])
		 diff++;
     }
     if(min > diff)
	     min = diff;
 }
 printf("%d\n",min);
 free(a);
 free(b);
 return 0;
}
