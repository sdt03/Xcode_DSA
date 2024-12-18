//
//  Stack.h
//  Graphs
//
//  Created by Shoumik Daterao on 02/05/23.
//

#ifndef Stack_h
#define Stack_h
#include<stdlib.h>

void push(){
    struct Node *t;
    int data;
    t=(struct Node*)malloc(sizeof(struct Node));
    if(t==NULL)
        printf("Stack is full\n");
    else{
        printf("Enter the value: ");
        scanf("%d",&data);
        t->data=data;
        t->next=top;
        top=t;
    }
}

int pop(){
    struct Node *p;
    int x=-1;
    
    if(top==NULL)
        printf("\nStack is empty\n");
    else{
        p=top;
        top=top->next;
        x=p->data;
        free(p);
    }
    return x;
}


#endif /* Stack_h */
