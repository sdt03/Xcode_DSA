//
//  LLchain.h
//  Hashing
//
//  Created by Shoumik Daterao on 07/05/23.
//

#ifndef LLchain_h
#define LLchain_h
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};

void InsertSorted(struct Node **H, int data){
    struct Node *t,*q=NULL,*p=*H;
    
    t=(struct Node*)malloc(sizeof(struct Node));
    t->data=data;
    t->next=NULL;
    
    if(*H==NULL){
        *H=t;
    }
    else{
        while(p && p->data<data){
            q=p;
            p=p->next;
        }
        if(p==*H){
            t->next=*H;
            *H=t;
        }
        else{
            t->next=q->next;
            q->next=t;
        }
    }
}

struct Node *search(struct Node *p, int key){
    while(p!=NULL){
        if(key==p->data){
            return p;
        }
        p=p->next;
    }
    return NULL;
}

#endif /* LLchain_h */
