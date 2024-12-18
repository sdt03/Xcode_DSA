#include<stdio.h>
#include<stdlib.h>

struct Node{
    struct Node *lchild;
    int data;
    struct Node *rchild;
}*root=NULL;

void Insert(int key){
    struct Node *t=root;
    struct Node *r=NULL;
    struct Node *p;
     
    if(root==NULL)
    {
        p=(struct Node*)malloc(sizeof(struct Node));
        p->data=key;
        p->lchild=p->rchild=NULL;
        root=p;
        return;
    }
    while(t!=NULL){
        r=t;
         if(key<t->data)
            t=t->lchild;
        else if(key>t->data)
            t=t->rchild;
        else
            return;
    }
    p=(struct Node*)malloc(sizeof(struct Node));
    p->data=key;
    p->lchild=p->rchild=NULL;
    
    if(key<r->data)
        r->lchild=p;
    else
        r->rchild=p;
    
}

struct Node *RInsert(struct Node *p, int key){
    struct Node *t=NULL;
    if(p==NULL){
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=key;
        t->lchild=t->rchild=NULL;
        return t;
    }
    if(key<p->data){
        p->lchild=RInsert(p->lchild, key);
    }
    else if(key>p->data){
        p->rchild=RInsert(p->rchild, key);
    }
    return p;
}

struct Node *InPre(struct Node *p){
    while(p!=NULL && p->rchild!=NULL)
        p=p->rchild;
    return p;
}

struct Node *InSucc(struct Node *p){
    while(p!=NULL && p->lchild!=NULL)
        p=p->lchild;
    return p;
}

int height(struct Node *p){
    int x,y;
    if(p==NULL)
        return 0;
    else
    {
        x=height(p->lchild);
        y=height(p->rchild);
        if(x>y)return x+1;
        else return y+1;
    }
    return 1;
}

struct Node *Delete(struct Node *p, int key){
    struct Node *q=NULL;
    if(p==NULL)
        return NULL;
    if(p->lchild==NULL && p->rchild==NULL){
        if(p==root)
            root=NULL;
        free(p);
        return NULL;
    }
    
    if(key<p->data){
        p->lchild=Delete(p->lchild, key);
    }
    else if (key>p->data){
        p->rchild=Delete(p->rchild, key);
    }
    else{
        if(height(p->lchild)>height(p->rchild)){
            q=InPre(p->lchild);
            p->data=q->data;
            p->lchild=Delete(p->lchild, q->data);
        }
        else{
            q=InSucc(p->rchild);
            p->data=q->data;
            p->rchild=Delete(p->rchild, key);
        }
    }
    return p;
}


void Inorder(struct Node *p){
    if(p){
        Inorder(p->lchild);
        printf("%d ",p->data);
        Inorder(p->rchild);
    }
}

int main(){
    Insert(10);
    Insert(8);
    Insert(18);
    Insert(3);
    Insert(23);
        
    RInsert(root, 12);
    
    Inorder(root);
    Delete(root, 8);
    printf("\n");
    Inorder(root);
    return 0;
}
