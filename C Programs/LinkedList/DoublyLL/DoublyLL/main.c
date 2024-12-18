#include<stdio.h>
#include<stdlib.h>

struct Node{
    struct Node *prev;
    int data;
    struct Node *next;
}*first=NULL;

void Create(int A[], int n){
    int i;
    struct Node *t, *last;
    
    first=(struct Node*)malloc(sizeof(struct Node));
    first->data=A[0];
    first->next=first->prev=NULL;
    last = first;
    
    for(i=1;i<n;i++){
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=NULL;
        t->prev=last;
        last->next=t;
        last=t;
    }
}

void Display(struct Node *p){
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
}

int count(struct Node *p){
    int c=0;
    while(p!=NULL){
        c++;
        p=p->next;
    }
    return c;
}

void Insert(struct Node *p,int index, int x){
    struct Node *t;
    int i;
    
    if(index<0 || index>count(p))
        return;
    if(index==0){
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=x;
        t->prev=NULL;
        t->next=first;
        first->prev=t;
        first = t;
    }
    else{
        for(i=0;i<index-1;i++){
            p=p->next;
        }
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=x;
        t->prev=p;
        t->next=p->next;
        p->next=t;
        if(p->next!=NULL)
            t->next->prev=t;
        }
}

int Delete(struct Node *p, int index){
    int x=-1;
    int i;
    p=first;
    if(index<0||index>count(p)){
        return -1;
    }
    if(index==0){
        first=first->next;
        first->next=NULL;
        x=p->data;
        free(p);
    }
    else{
        for(i=0;i<index-1;i++)
            p=p->next;
        p->prev->next=p->next;
        if(p->next!=NULL)
            p->next->prev=p->prev;
        x=p->data;
        free(p);
    }
    return x;
}

void Reverse(struct Node *p){
    struct Node *temp;
    while(p!=NULL){
        temp=p->next;
        p->next=p->prev;
        p->prev=temp;
        p=p->prev;
        if(p!=NULL && p->next==NULL)
            first=p;
    }
}


int main(){
    int A[]={1,2,3,4,5,6};
    Create(A, 6);
    Display(first);
    
    Insert(first, 5, 10);
    printf("\nAfter insertion: ");
    Display(first);
    
    Reverse(first);
    printf("\nAfter reversing: ");
    Display(first);
    return 0;
}
