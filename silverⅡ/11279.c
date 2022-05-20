#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int swap(int *a,int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
int main(void){
    int num, cur = 0;
    scanf("%d", &num);
    int ins, up;
    int *array = (int *)malloc(sizeof(int) * (num + 2));
    memset(array, 0, num + 2);
    for (int i = 0; i < num; i++){
        scanf("%d", &ins);
        if (ins == 0){
            if (cur == 0)
                printf("0\n");
            else{
                printf("%d\n", array[1]);
                array[1] = 0;
                swap(&array[1],&array[cur]);
                up = 1;
                while (up <= cur){
                    if (array[up] < array[up * 2] && array[up * 2] >= array[up * 2 + 1]){
						swap(&array[up],&array[up * 2]);
						up = up * 2;
					}
					else if (array[up] < array[up * 2 + 1] && array[up * 2] <= array[up * 2 + 1]){
						swap(&array[up],&array[up * 2 + 1]);
						up = up * 2 + 1;
					}
					else
						break;
                }
                cur--;
            }
        }
        else{
            cur++;
            array[cur] = ins;
            up = cur;
            while (up > 1){
                if (array[up / 2] < array[up]){
                    swap(&array[up/2],&array[up]);
                }
                up /= 2;
            }
        }
    }
    free(array);
}