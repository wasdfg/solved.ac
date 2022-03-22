#include<stdio.h>
int sorted[10001];
int sort(int *a,int b,int c,int d){
    int i,j,k,l;
    i = b;
    j = c+1;
    k = b;
    while(i <= c && j <= d){
      if(a[i] <= a[j])
	sorted[k++] = a[i++];
      else
	      sorted[k++] = a[j++];
    }
    if(i > c){
      for(l = j;l <= d;l++)
	      sorted[k++] = a[l];
    }
    else{
    for(l = i;l <= c;l++)
	    sorted[k++] = a[l];
    }
    for(l=b;l<=d;l++){
     a[l] = sorted[l];
    }
}
int merge(int *a,int b,int c){
   int mid;
   if(b < c){
   mid = (b+c)/2;
   merge(a,b,mid);
   merge(a,mid+1,c);
   sort(a,b,mid,c);
   }
}
int check(int *a,int b,int c,long long d){
    long long num = 0;
   for(int i = 0;i < b;i++){
        num += (a[i] / d);
   }
   if(num >= c){
	return 0;
   }
   else if(num < c){
	   return 1;
   }
}
int main(void){
  int a,b;
  long long min,max,mid;
  scanf("%d",&a);
  scanf("%d",&b);
  int c[a+1];
  for(int i = 0;i < a;i++){
   scanf("%d",&c[i]);
  }
  merge(c,0,a-1);
  min = 0;
  max = c[a-1];
  while(min <= max){
     mid = ((min+max) / 2);
     if(mid == 0)
	     mid = 1;
     if(check(c,a,b,mid) == 0){
        min = mid+1;
     }
     else if(check(c,a,b,mid) == 1){
	     max = mid -1;
     }
  }
  printf("%lld\n",max);
}
