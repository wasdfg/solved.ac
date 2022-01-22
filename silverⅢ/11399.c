#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int *merging;
int merge(int *list, int left, int mid, int right){
	int i, j, k, l;
	i = left;
	j = mid+1;
	k = left;

	while(i<=mid && j<=right){
		if(list[i]<=list[j])
			merging[k++] = list[i++];
		else
			merging[k++] = list[j++];
	}
	if(i>mid){
		for(l=j; l<=right; l++)
			merging[k++] = list[l];
	}
	else{
		for(l=i; l<=mid; l++)
			merging[k++] = list[l];
	}
	for(l=left; l<=right; l++){
		list[l] = merging[l];
	}
}
int mergesort(int *list, int left, int right){
	int mid;
	if(left<right){
		mid = (left+right)/2;
		mergesort(list, left, mid); 
		mergesort(list, mid+1, right);
		merge(list, left, mid, right);
	}
}
int main(void){
	int a,num;
	scanf("%d",&a);
	int *minute = (int*)malloc((a+1) * sizeof(int));
	merging = (int*)malloc((a+1) * sizeof(int));
	memset(minute,0,(a+1)*sizeof(int));
	memset(merging,0,(a+1)*sizeof(int));
	for(int i = 0; i < a;i++){
		scanf("%d",&num);
		minute[i] = num;
	}
	mergesort(minute,0,a-1);
	int taketime = 0,totaltime = 0;
	for(int i = 0; i < a; i++){
	  taketime += minute[i];
	  totaltime += taketime;
	}
	printf("%d\n",totaltime);
	free(minute);
	free(merging);
}
