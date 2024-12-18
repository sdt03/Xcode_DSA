#include <stdio.h>
#include<stdbool.h>
int stack[100],choice,n,top,x,i;
void push(void);
void pop(void);
void display(void);
void peek(void);
bool isempty(void);
bool isfull(void);
bool isbalance(void);
int main() {
    top = -1;
    printf("Enter the size of stack: ");
    scanf("%d",&n);
    printf("\nStack operations using array");
    printf("\n1. Push\n2. Pop\n3. Display\n4. Peek\n5. IsEmpty\n6. IsFull\n7. Exit\n");
    do {
        printf("\nEnter the choice: ");
        scanf("%d",&choice);
    switch(choice){
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            peek();
            break;
        case 5:
            isempty();
            break;
        case 6:
            isfull();
        case 7:
            isbalance();
        case 8:
            printf("exiting...");
        default:
            printf("wrong choice");
    }
    }
    while(choice!=7);
    return 0;
}
void push(){
    if(top>=n-1){
        printf("\nStack is over flow");
    }
    else{
        printf("Enter a value ot be pushed: ");
        scanf("%d",&x);
        top++;
        stack[top]=x;
    }
}
void pop(){
    if(top<=-1)
    {
        printf("\n\t Stack is under flow");
    }
    else
    {
        printf("\n\t The popped elements is %d",stack[top]);
        top--;
    }
}
void display(){
    if(top>=0){
        printf("\nThe element in Stack \n");
        for(i=top; i>=0; i--)
            printf("\n%d",stack[i]);
        printf("\n Press Next Choice");
    }
    else{
        printf("\n The stack is empty");
    }

}
void peek(){
    int x = stack[top];
    printf("Outermost value of stack is : %d\n",x);
}

bool isempty(){
    if(top==-1)
        return true;
    printf("Stack is empty\n");
    return false;
}

bool isfull(){
    if(top==n-1)
        return true;
    printf("Stack is full \n");
    return false;
}



