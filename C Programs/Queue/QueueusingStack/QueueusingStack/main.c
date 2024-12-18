#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

struct Stack {
    int top;
    int items[MAXSIZE];
};

void push(struct Stack* stack, int item) {
    if (stack->top == MAXSIZE - 1) {
        printf("Stack overflow\n");
        exit(1);
    } else {
        stack->items[++(stack->top)] = item;
    }
}

int pop(struct Stack* stack) {
    if (stack->top == -1) {
        printf("Stack underflow\n");
        exit(1);
    } else {
        return stack->items[(stack->top)--];
    }
}

int peek(struct Stack* stack) {
    return stack->items[stack->top];
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

struct Queue {
    struct Stack* s1;
    struct Stack* s2;
};

void enqueue(struct Queue* queue, int item) {
    push(queue->s1, item);
}

int dequeue(struct Queue* queue) {
    if (isEmpty(queue->s2)) {
        while (!isEmpty(queue->s1)) {
            push(queue->s2, pop(queue->s1));
        }
    }
    if (isEmpty(queue->s2)) {
        printf("Queue is empty\n");
        exit(1);
    } else {
        return pop(queue->s2);
    }
}


int main() {
    struct Stack stack1, stack2;
    struct Queue queue;
    queue.s1 = &stack1;
    queue.s2 = &stack2;
    queue.s1->top = queue.s2->top = -1;
    int choice, item;
    while (1) {
        printf("Enter your choice:\n1. Enqueue\n2. Dequeue\n3. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter item to enqueue: ");
                scanf("%d", &item);
                enqueue(&queue, item);
                break;
            case 2:
                printf("Dequeued item: %d\n", dequeue(&queue));
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
