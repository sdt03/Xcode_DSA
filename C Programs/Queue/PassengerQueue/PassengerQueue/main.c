#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node{
    char name[50];
    int no;
    int token;
    struct Node *next;
}*front=NULL, *rear=NULL;

void Enqueue(char name[], int no, int token){
    struct Node *p=NULL;
    p=(struct Node*)malloc(sizeof(struct Node));
    if(p==NULL)
        printf("Queue is full\n");
    else{
        strcpy(p->name, name);
        p->no=no;
        p->token=token;
        p->next=NULL;
        if(front==NULL)
            front=rear=NULL;
        else{
            rear->next=p;
            rear=p;
        }
    }
}

void Display(){
    struct Node *p=front;
    while(p!=NULL){
        printf("Name: %s, Phone NO: %d, Token: %d",p->name,p->no,
               p->token);
        p->next=NULL;
    }
}

int main(){
    Enqueue("Shoumik", 91732 , 1);
    Display();
    return 0;
}
