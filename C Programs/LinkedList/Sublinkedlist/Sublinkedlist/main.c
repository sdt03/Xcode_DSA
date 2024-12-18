#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
}*first;

void create(int A[], int n){
    int i;
    struct Node *last, *t;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last=first;
    
    for(i=1;i<n;i++){
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void Display(struct Node *p){
    while(p!=NULL){
        printf("%d\t",p->data);
        p=p->next;
    }
}
int count(struct Node *p){
    int c = 0;
    while(p!=NULL){
        c++;
        p=p->next;
    }
    return c;
}
void Duplicate(struct Node *p){
    struct Node *q;
    q=p->next;
    while(q!=0){
        if(p->data!=q->data)
        {
            p=q;
            q=q->next;
        }
        else{
            p->next=q->next;
            free(q);
            q=p->next;
        }
        
    }
}

void Reverse(struct Node *p){
    struct Node *q=NULL, *r=NULL;
    while(p!=NULL)
    {
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    first = q;
}


int main()
{
    int A[]={1,2,4,4,5};
    //int B[]={6,7,8,9,10};
    
    create(A, 5);
    //create(B,5);
    
    Reverse(first);
    Display(first);
    return 0;
}
