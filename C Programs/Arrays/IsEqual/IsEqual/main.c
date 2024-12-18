#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

void swap(int *x, int *y){
    int temp;
    temp = *x;
    *x=*y;
    *y = temp;
}

void BubbleSort(int A[], int B[],int n){
    int i,j;
    //int n;
    int flag1=0;
    int flag2=0;
    
    for(i=0;i<n;i++){
        for(j=0;j<n-i-1;j++){
            if(A[j]>A[j+1]){
                swap(&A[j],&A[j+1]);
                flag1=1;
            }
        }
        if(flag1==0)
        break;
    }
    for(i=0;i<n;i++){
        for(j=0;j<n-i-1;j++){
            if(B[j]>B[j+1]){
                swap(&B[j],&B[j+1]);
                flag2=1;
            }
        }
        if(flag2==0)
        break;
    }
}

bool IsSame(int A[], int B[], int n){
    
    int i;
    int flag=0;
    BubbleSort(A,B,n);
    for(i=0;i<n;i++){
        if(A[i]==B[i])
            flag++;
    }
    return(flag==n)?true:false;
}

int main(){
    int n=5;
    int A[]={1,3,8,2,5};
    int B[]={5,3,1,2,8};
    
    if(IsSame(A,B,n))
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
    
}
