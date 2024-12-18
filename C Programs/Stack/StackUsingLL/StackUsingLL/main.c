#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
}*top=NULL;

void Display(){
    struct Node *p;
    p=top;
    while(p!=NULL){
        printf("%d\n",p->data);
        p=p->next;
    }
}

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
void peek(){
    struct Node *p;
    p=top;
    int x = p->data;
    printf("Outermost value of stack is %d\n",x);
}

int main(){
    int n;
    
    printf("1.Push\n2. Pop\n3. Display\n4. peek\n5. Exit\n");
    
    do{
        printf("Choose: ");
        scanf("%d",&n);
        switch(n){
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                Display();
                break;
            case 4:
                peek();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Wrong choice\n");
                break;
        }
            
    }while(n!=5);
    return 0;
}
