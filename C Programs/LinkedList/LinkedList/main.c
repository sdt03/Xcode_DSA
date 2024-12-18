#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>

struct Node{
    int data;
    struct Node *next;
}*first=NULL,*second=NULL,*third=NULL;

void create(int A[], int n){
    int i;
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next=NULL;
    last=first;
    
    for(i=1;i<n;i++){
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last = t;
    }
}

void create2(int B[], int n){
    int i;
    struct Node *t, *last;
    second = (struct Node *)malloc(sizeof(struct Node));
    second->data = B[0];
    second->next=NULL;
    last=second;
    
    for(i=1;i<n;i++){
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=B[i];
        t->next=NULL;
        last->next=t;
        last = t;
    }
}

void Display(struct Node *p){
    while(p!=NULL){
        printf("%d\t",p->data);
        p=p->next;//traversal of linked list
    }
}
void RDisplay(struct Node *p){
    if(p!=NULL){
        printf("%d\t",p->data);
        RDisplay(p->next);
    }
}
int Count(struct Node *p){
    int c = 0;
    while(p!=0){
        c++;
        p=p->next;
    }
    return c;
}
int Sum(struct Node *p){
    int sum = 0;
    while(p!=0){
        sum = sum + p->data;
        p=p->next;
    }
    return sum;
}
int Max(struct Node *p){
    int m=-32768;//MIN_INT value
    while(p!=0){
        if(p->data>m)
            m = p->data;
        p=p->next;
    }
    return m;
}
int RMax(struct Node *p){
    int x=0;
    if(p==0)
        return 0;
    x = RMax(p->next);
    return x>p->data?x:p->data;
    
}
struct Node * LSearch(struct Node *p, int key){
    struct Node *q=NULL;
    
    while(p!=0){
        if(key == p->data){
            q->next = p->next;
            p->next = first;
            first=p;
            return p;
        }
        q=p;
        p=p->next;
    }
    return NULL;
}
void Insert(struct Node *p, int index, int x){
    struct Node *t;
    int i;
    if(index<0|| index > Count(p))
        return;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data=x;
    if(index==0){
        t->next = first;
        first = t;
    }
    else{
        for(i=0;i<index-1 && p;i++)
            p=p->next;
        p->next=t->next;
        p->next = t;
    }
}
void InsertLast(struct Node *p, int x){
    struct Node *t;
    struct Node *last=NULL;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;
    if(first==NULL)
        first=last=t;
    else{
        last->next = t;
        last = t;
    }
}
void InsertSorted(struct Node *p, int x){
    struct Node *t, *q=NULL;
    t=(struct Node *)malloc(sizeof(struct Node));
    t->data=x;
    t->next=NULL;
    if(p==NULL){
        first = t;
    }
    else{
        while(p && p->data<x){
            q=p;
            p=p->next;
        }
         if(p==NULL){
            t->next = NULL;
            first = t;
        }
        else{
            t->next = q->next;
            q->next = t;
        }
    }
}

int Delete(struct Node *p, int index){
    struct Node *q=NULL;
    int x=-1;
    int i;
    if(index<1 || index > Count(p))
        return -1;
    if(index==1){
        q=first;
        x = first->data;
        first = first->next;
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
}
int IsSorted(struct Node *p){
    int x = -32672;
    while(p!=NULL){
        if(p->data < x)
            return 0;
        x=p->data;
        p=p->next;
    }
    return 1;
}
void Duplicate(struct Node *p){
    struct Node *q;
    q = p->next;
    while(q!=0){
        if(p->data!=q->data){
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
void Reverse(struct Node *p){//sliding pointers
    struct Node *q=NULL;
    struct Node *r=NULL;
    while(p!=NULL){
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    first = q;
}

void Reverse2(struct Node *p, struct Node *q){
    if(p){
        Reverse2(p, p->next);
        p->next=q;
    }
    else
        first=q;
}

void Concat(struct Node *p, struct Node *q){
    third = p;
    while(p->next!=NULL)
        p=p->next;
    p->next=q;
}

void Merge(struct Node *p, struct Node *q){
    struct Node *last;
    if(p->data<q->data){
        third=last=p;
        p=p->next;
        third->next=NULL;
    }
    else{
        third=last=q;
        q=q->next;
        third->next=NULL;
    }
    while(p&&q){
        if(p->data<q->data){
            last->next=p;
            last=p;
            p=p->next;
            last->next=NULL;
        }
        else{
            last->next=q;
            last=q;
            q=q->next;
            last->next=NULL;
        }
    }
    if(p)last->next=p;
    if(q)last->next=q;
}

struct Node* Removeduplicates(struct Node *p){
    p=first;
    struct Node *q=first;
    while(q!=NULL && q->next!=NULL){
        if(q->data==q->next->data){
            q->next=q->next->next;
        }
        else{
            q=q->next;
        }
    }
    return p;
}

bool isLoop(struct Node *f){
    struct Node *p=first;
    struct Node *q=first;
    while(p!=NULL && q->next!=NULL){
        p=p->next;
        q=q->next->next;
        if(p==q)
            return true;
    }
    return false;
    
}


int main() {
    //struct Node *temp;
    
    int A[]={5,5,5,23,25};
    create(A,5);
    int B[]={9,18,27,36,45};
    create2(B, 5);
    
    printf("First: ");
    Display(first);
    printf("\n");
    Removeduplicates(first);
    Display(first);
    
    isLoop(first);
    /*printf("\nSecond: ");
    Display(second);
    printf("\n");
    
    Merge(first, second);
    Display(third);*/
    return 0;
}
