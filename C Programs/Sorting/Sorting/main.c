#include <stdio.h>

void Swap(int *x, int *y){
    int temp=*x;
    *x=*y;
    *y=temp;
}

void Bubble(int A[], int n){
    int i,j;
    int flag;
    flag = 0;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(A[j]>A[j+1]){
                Swap(&A[j],&A[j+1]);
                flag = 1;
            }
        }
        if(flag==0)
            break;
    }
}


void InsertionSort(int A[], int n){
    int i,j,x;
    for(i=1;i<n;i++){
        j=i-1;
        x=A[i];
        while(j>-1 && A[j]>x){
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=x;
    }
}

int partition(int A[], int l, int h){
    int pivot = A[l];
    int i=l, j=h;
    do{
        do{i++;}while(A[i]<=pivot);
        do{j--;}while(A[j]>pivot);
        if(i<j)Swap(&A[i], &A[j]);
    }while(i<j);
    Swap(&A[l], &A[j]);
    return j;
}
void Quicksort(int A[], int l, int h){
    int j;
    if(l<h){
        j=partition(A, l, h);
        Quicksort(A, l, j);
        Quicksort(A, j+1, h);
    }
}

int main() {
    int A[]={1,3,4,9,10,8,7,2,5,6,65535};
    //Quicksort(A, 0, 10);
    
    int i;
    InsertionSort(A, 10);
    //Bubble(A, 10);
    for(i=0;i<10;i++)
        printf("%d ",A[i]);
    return 0;
}
