#include<stdio.h>
#include<stdlib.h>


int NGE(int A[], int n){
    int i;
    int num1=-1;
    int num2=-1;
    int count1=0;
    int count2=0;
    
    for(i=0;i<n;i++){
        if(A[i]==num1)
            count1++;
        else if(A[i]==num2)
            count2++;
        else if(count1==0){
            num1=A[i];
            count1++;
        }
        else if (count2==0){
            num2=A[i];
            count2++;
        }
        else{
            count1--;
            count2--;
        }
    }
    count1=0;
    count2=0;
    
    for(i=0;i<n;i++){
        if(A[i]==num1)
            count1++;
        else if(A[i]==num2)
            count2++;
    }
    if(count1>n/3)
        return num1;
    else if(count2>n/3)
        return num2;
    else return -1;
}

int main(){
    int A[]={1,2,3,1,1,2};
    int n = sizeof(A)/sizeof(A[0]);
    printf("%d ",NGE(A, n));
    return 0;
    
}
