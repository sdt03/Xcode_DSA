#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
}*first;

void create(int A[], int n)
{
    int i;
    struct Node *t, *last;
    first = (struct Node*)malloc(sizeof(struct Node));
    first->data=A[0];
    first->next=NULL;
    last = first;
    
    for(i=1;i<n;i++){
        t=(struct Node*)malloc(sizeof(struct Node));
            t->data=A[i];
            t->next=NULL;
            last->next=t;
            last = t;
        
    }
}

void Display(struct Node *p){
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
}
int Count(struct Node *p){
    int c=0;
    while(p!=NULL){
        c++;
    }
    return c;
}

int delete(struct Node *p, int index){
    int x=-1;
    int i;
    struct Node *q=NULL;
    if(index==1){
        q=first;
        x=first->data;
        first=first->next;
        free(q);
        return x;
    }
    else{
        for(i=0;i<index-1;i++){
            q=p;
            p=p->next;
        }
        q->next=p->next;
        x=p->data;
        free(p);
        return x;
    }
    return x;
}

void Reorder(struct Node *q, int n){
    struct Node *p, *r=NULL;
    q=first;
    while(q!=NULL){
        p=q->next;
        q->next=r;
        r=q;
        q=p;
    }
    first=r;
}


int main(){
    int A[]={1,2,3,4};
    create(A,4);
    /*Display(first);
    printf("\nRemoving Element\n");
    delete(first, 3);
    Display(first);*/
    Reorder(first, 4);
    Display(first);
    
}
