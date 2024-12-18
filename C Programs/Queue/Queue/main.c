#include <stdio.h>
#include<stdlib.h>
struct Queue{
    int size;
    int Front,Rear;
    int *Q;
};

void Create(struct Queue *q,int size){
    q->size = size;
    q->Front = q->Rear = -1;
    q->Q=(int*)malloc(q->size*sizeof(int));
}

void enqueue(struct Queue *q,int x){
    if(q->Rear==q->size-1)
        printf("Queue is Full\n");
    else{
        q->Rear++;
        q->Q[q->Rear]=x;
    }
}

int dequeue(struct Queue *q){
    int x = -1;
    if(q->Front==q->Rear)
        printf("Queue is Empty\n");
    else{
        q->Front++;
        x=q->Q[q->Front];
    }
    return x;
}
void Display(struct Queue q){
    int i;
    for(i=q.Front+1;i<=q.Rear;i++)
        printf("%d ",q.Q[i]);
    printf("\n");
}
//for cicular queue
void Enqueue(struct Queue *q, int x){
    if((q->Rear+1)%q->size==q->Front)
        printf("Queue is full\n");
    else{
        q->Rear=(q->Rear+1)%q->size;
        q->Q[q->Rear]=x;
    }
}
//for cicular queue
int Dequeue(struct Queue *q){
    int x =-1;
    if(q->Rear==q->Front)
        printf("Queue is empty\n");
    else{
        q->Front=(q->Front+1)%q->size;
        x=q->Q[q->Front];
    }
    return x;
}
//for cicular queue
void display(struct Queue q){
    int i=q.Front+1;
    do{
        printf("%d\n",q.Q[i]);
        i=(i+1)%q.size;
    }while(i!=(q.Rear+1)%q.size);
    printf("\n");
}

int main() {
    
    struct Queue q;
    Create(&q,5);
    Enqueue(&q, 10);
    Enqueue(&q, 20);
    Enqueue(&q, 30);
    
   
    display(q);
    printf("Dequeue %d\n",Dequeue(&q));
    display(q);
    return 0;
}



