#include<stdio.h>
#include<stdlib.h>
#define size 100

struct stack1{
    int a[size];
    int top1;
}s;

struct stack2{
    int b[size];
    int top2;
}s1;

void push1(){
    int x;
    if(s.top1==size-1){
        printf("Stack is full\n");
    }
    else{
        printf("Enter the value to be pushed in stack 1: ");
        scanf("%d",&x);
        s.top1++;
        s.a[s.top1]=x;
    }
}

void push2(){
    int x;
    if(s1.top2==size-1){
        printf("Stack is full\n");
    }
    else{
        printf("Enter the value to be pushed in stack2: ");
        scanf("%d",&x);
        s1.top2++;
        s1.b[s1.top2]=x;
    }
}

int pop1(){
    int x=-1;
    if(s.top1==-1){
        printf("Stack is empty\n");
    }
    else{
        x=s.a[s.top1];
    }
    return x;
}

int pop2(){
    int x=-1;
    if(s1.top2==-1){
        printf("Stack is empty\n");
    }
    else{
        x=s1.b[s1.top2];
    }
    return x;
}

int stackfull1(){
    if(s.top1==size-1)
        return 1;
    else
        return 0;
}

int stackfull2(){
    if(s1.top2==size-1)
        return 1;
    else
        return 0;
}

int stackempty1(){
    if(s.top1==-1)
        return 1;
    else
        return 0;
}

int stackempty2(){
    if(s1.top2==-1)
        return 1;
    else
        return 0;
}

void Displaystack1(){
    int i;
    printf("Elements in stack 1: ");
    if(s.top1==-1)
        printf("stack is empty\n");
    else{
        for(i=s.top1;i>=0;i--){
            printf("%d\n",s.a[i]);
        }
    }
}

void Displaystack2(){
    int i;
    printf("Elements in stack 1: ");
    if(s1.top2==-1)
        printf("stack is empty\n");
    else{
        for(i=s1.top2;i>=0;i--){
            printf("%d\n",s1.b[i]);
        }
    }
}

int main(){
    int n;
    printf("Select any of the options\n");
    printf("1.Push in stack1\n");
    printf("2.Push in stack2\n");
    printf("3.Pop from stack1\n");
    printf("4.Pop from stack2\n");
    printf("5.Check if stack1 is full\n");
    printf("6.Check if stack2 is full\n");
    printf("7.Check if stack1 is empty\n");
    printf("8.Check if stack2 is empty\n");
    printf("9.Display stack1\n");
    printf("10.Display stack2\n");
    do{
        printf("Choose: ");
        scanf("%d",&n);
        switch(n){
            case 1:
                push1();
                break;
            case 2:
                push2();
                break;
            case 3:
                pop1();
                break;
            case 4:
                pop2();
                break;
            case 5:
                stackfull1();
                break;
            case 6:
                stackfull2();
                break;
            case 7:
                stackempty1();
                break;
            case 8:
                stackempty2();
                break;
            case 9:
                Displaystack1();
                break;
            case 10:
                Displaystack2();
                break;
            default:
                printf("Choose Again\n");
                break;
        }
    }while(n!=10);
    return 0;
}
