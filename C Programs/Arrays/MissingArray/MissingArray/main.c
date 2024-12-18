//
//  main.c
//  MissingArray
//
//  Created by Shoumik Daterao on 24/03/23.
//

#include <stdio.h>
#include<stdlib.h>
struct Array{
    int *A,size,length;
};
void Display(struct Array arr){
    int i;
    for(i=0;i<arr.length-1;i++)
        printf("%d\t",arr.A[i]);
}
void Missing(struct Array *arr, int size){
    int i;
    int diff;
    int n = size +1;
    diff = arr->A[0]-0;
    for(i=0;i<arr->size;i++){
        if(arr->A[i]-i!=diff){
            while(diff<arr->A[i]-i)
                printf("%d\n",i + diff);
            diff++;
        }
    }
}

int main() {
        struct Array arr;
        int i,n;
        printf("Enter the size of array\n");
        scanf("%d",&arr.size);
        arr.A = (int *)malloc(arr.size*sizeof(int));
        arr.length=0;
        
        printf("Enter the no of elements\n");
        scanf("%d",&n);
        printf("Enter the elements\n");
        for(i=0;i<n;i++){
            scanf("%d",&arr.A[i]);
        }
        arr.length=n;
    
    Missing(&arr,10);
    Display(arr);
    return 0;
}

