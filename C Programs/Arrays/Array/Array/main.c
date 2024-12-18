#include <stdio.h>
#include <stdlib.h>
struct Array{
    int *A,size,length;
};
void Display(struct Array arr){
    int i;
    printf("elements are: \n");
    for(i=0;i<arr.length;i++)
        printf("%d\t",arr.A[i]);
}
void append(struct Array *arr,int x){
    if(arr->length<arr->size)
        arr->A[arr->length++] = x;
}

void Insert(struct Array *arr,int index,int x){
    int i;
    if(index>=0 && index<=arr->length)
    {
        for(i=arr->length;i>index;i--)
            arr->A[i] = arr->A[i-1];
        arr->A[index]=x;
        arr->length++;
    }
}
int Delete(struct Array *arr, int index){
    int x = 0;
    int i;
    x=arr->A[index];
    if(index>=0 && index<arr->length)
    {
        for(i=index; i<arr->length-1; i++)
            arr->A[i] = arr->A[i+1];
        arr->length--;
        return x;
    }
    return 0;
}
void swap(int *x, int *y){
    int temp;
    temp = *x;
    *x=*y;
    *y = temp;
}
int LinearSearch(struct Array *arr, int key){
    int i;
    for(i=0;i<arr->length;i++){
        if(arr->A[i]==key){
            swap(&arr->A[i],&arr->A[i-1]);
            return i;
        }
    }
    return -1;
}

int BinarySearch(struct Array *arr,int key){
    int l,h,mid;
    l=0;
    h=arr->length-1;
    while(l<=h){
        mid = l+h/2;
        if(key==arr->A[mid])
            return mid;
        else if(key<arr->A[mid])
            h=mid-1;
        else
            l = mid+1;
        
    }
    return -1;
}
int Get(struct Array *arr, int index){
    if(index>=0 && index<arr->length)
        return index;
    return -1;
}
int Set(struct Array *arr, int index, int x){
    if(index>=0 && index<arr->length)
        arr->A[index]=x;
    return index;
}
int Max(struct Array *arr){
    int max = arr->A[0];
    int i;
    for(i=0;i<arr->length;i++){
        if(arr->A[i]>arr->A[0])
            max = arr->A[i];
    }
    return max;
}
int Min(struct Array *arr){
    int min = arr->A[0];
    int i;
    for(i=0;i<arr->length;i++){
        if(arr->A[0]>arr->A[i])
            min = arr->A[i];
    }
    return min;
}
void Reverse(struct Array *arr){
    int *B;
    int i,j;
    B = (int *)malloc(arr->length*sizeof(int));
    for(i=arr->length, j=0; i>=0;i--,j++)
        B[i]=arr->A[i];
    for(i=0;i<arr->length;i++)
        arr->A[i] = B[i];
    for(i=0;i<arr->length;i++)
        printf("%d\t",arr->A[i]);
}
void Reverse2(struct Array *arr){
    int i,j;
    for(i=0,j=arr->length-1;i<j;i++,j--)
        swap(&arr->A[i],&arr->A[j]);
}
void insertSort(struct Array *arr, int x){
    int i = arr->length-1;
    if(arr->length==arr->size)
        return;
    while(i>=0 && arr->A[i]>x){
        arr->A[i+1]=arr->A[i];
        i--;
    }
    arr->A[i+1]=x;
    arr->length++;
}
void Rearrange(struct Array *arr){
    int i,j;
    i=0;
    j=arr->length-1;
    while(i<j){
        while(arr->A[i]<0)i++;
        while(arr->A[j]>0)j--;
        if(i<j)swap(&arr->A[i],&arr->A[j]);
    }
}

struct Array* Merge(struct Array *arr1, struct Array *arr2){
    int i,j,k;
    i=j=k=0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
    while(i<arr1->length && j<arr2->length){
            if(arr1->A[i]<arr2->A[j])
                arr3->A[k++]=arr1->A[i++];
            else
                 arr3->A[k++]=arr2->A[j++];
    }
    for(;i<arr1->length;i++)
        arr3->A[k++]=arr1->A[i];
    for(;j<arr1->length;j++)
        arr3->A[k++]=arr1->A[j];
    arr3->length = arr1->length+arr2->length;
    arr3->size=10;

    return arr3;
}


int main(){
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
 
    //printf("Deleted no is %d\n",Delete(&arr,3));
    //printf("%d\n",LinearSearch(&arr, 4));
    //printf("%d\n",BinarySearch(&arr, 10));
    //printf("Element is %d\n",Set(&arr, 6,1003 ));
    //printf("Max no is %d\n",Max(&arr));
    //Reverse2(&arr);
    //insertSort(&arr, 12);
    //Rearrange(&arr);
    Display(arr);

    return 0;
}
