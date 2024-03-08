#include <stdio.h>
#include <stdlib.h>

void swap(int *x,int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

int *bubble_count(int *array, int size, int *swaps){

    int *tarray = (int *)malloc(sizeof(int)*size);
    int *tswaps = (int *)malloc(sizeof(int)*size);

    printf(" !%d! ", sizeof(tarray));

    if(tarray==NULL || tswaps == NULL){
        printf("malloc failed");
        return NULL;
    }

    for(int i=0;i<size;i++){
        tarray[i]=array[i];
        tswaps[i]=swaps[i];
    }

    int total = 0;
    for(int i=0;i<size;i++){
        for(int j=0;j<size-i-1;j++){
            if(tarray[j]>tarray[j+1]){
                swap(&tarray[j],&tarray[j+1]);
                swap(&tswaps[j],&tswaps[j+1]);
                tswaps[j]++;
                tswaps[j+1]++;
                total++;
            }
        }
    }
    for(int i=0;i<size;i++)
        printf("%d is swapped: %d times\n",tarray[i],tswaps[i]);

    free(tarray);
    free(tswaps);

    return total;
}

int *selection_count(int *array, int size, int *swaps){

    int *tarray = (int *)malloc(sizeof(int)*size);
    int *tswaps = (int *)malloc(sizeof(int)*size);

    if(tarray==NULL || tswaps == NULL){
        printf("malloc failed");
        return NULL;
    }

    for(int i=0;i<size;i++){
        tarray[i]=array[i];
        tswaps[i]=swaps[i];
    }

    int total = 0;

    int i,i_min;

    for(int i=0;i<size-1;i++){
        i_min = i;
        for(int j=i;j<size;j++){
            if(tarray[i_min]>tarray[j]){
                 i_min = j;
            }
        }
        swap(&tarray[i_min],&tarray[i]);
        swap(&tswaps[i_min],&tswaps[i]);
        tswaps[i_min]++;
        tswaps[i]++;
        total++;

    }

    for(int i=0;i<size;i++)
        printf("%d is swapped: %d times\n",tarray[i],tswaps[i]);

    free(tarray);
    free(tswaps);

    return total;
}

int main(){

//arrays input in here
    int array1[] = { 97, 16, 45, 63, 13, 22, 7, 58, 72 };
    int array2[] = { 90, 80, 70, 60, 50, 40, 30, 20, 10 };

    int size1 = sizeof(array1)/sizeof(int);
    int size2 = sizeof(array2)/sizeof(int);

    int swaps1[size1];
    for(int i=0; i<size1;i++)
        swaps1[i] = 0;
    int swaps2[size2];
    for(int i=0; i<size2;i++)
        swaps2[i] = 0;

    printf("BUBBLE SORT\n-----------------------\n");
    printf("Array 1:\n");
    printf("Total Bubble Swaps: %d\n", bubble_count(array1,size1,swaps1));


    printf("\n\nArray 2:\n");
    printf("Total Bubble Swaps: %d\n", bubble_count(array2,size2,swaps2));



printf("\n\nSELECTION SORT\n-----------------------\n");
    printf("Array 1:\n");
    printf("Total Selection Swaps: %d\n", selection_count(array1,size1,swaps1));



    printf("\n\nArray 2:\n");
    printf("Total Selection Swaps: %d\n", selection_count(array2,size2,swaps2));

    return 0;
}
