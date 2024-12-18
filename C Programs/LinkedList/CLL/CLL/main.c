#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
}*head=NULL;

void Create(int A[], int n){
    struct Node *t,*last;
    int i;
    head=(struct Node*)malloc(sizeof(struct Node));
    head->data=A[0];
    head->next=head;
    last=head;
    
    for(i=1;i<n;i++){
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=last->next;
        last->next=t;
        last=t;
    }
}

void Display(struct Node *p){
    do{
        printf("%d ",p->data);
        p=p->next;
    }while(p!=head);
    printf("\n");
}

int main(){
    int A[];
    int i;
    int n;
    printf("Enter no of elements: ");
    scanf("%d ",&n);
    printf("Enter elements: ");
    for(i=0;i<n;i++){
        scanf("%d ",&A[i]);
    }
}
