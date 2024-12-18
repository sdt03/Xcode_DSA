#include <iostream>

using namespace std;

class Queue{
private:
    int size;
    int front;
    int rear;
    int* Q;
public:
    Queue(int size);
    ~Queue();
    bool isFull();
    bool isEmpty();
    void Enqueue(int x);
    int Dequeue();
    void Display();
};

Queue::Queue(int size){
    this->size=size;
    front=-1;
    rear=-1;
    Q = new int[size];
}

Queue::~Queue(){
    delete []Q;
}

bool Queue::isFull(){
    if(rear==size-1)
        return true;
    else
        return false;
}

bool Queue::isEmpty(){
    if(front==rear){
        return true;
    }
    else
        return false;
}

void Queue::Enqueue(int x){
    if(isFull()){
        cout<<"Queue is full"<<endl;
    }
    else{
        rear++;
        Q[rear]=x;
    }
}

int Queue::Dequeue(){
    int x=-1;
    if(isEmpty()){
        cout<<"Queue is empty"<<endl;
    }
    else{
        front++;
        x=Q[front];
    }
    return x;
}

void Queue::Display(){
    for(int i = front+1;i<=rear;i++){
        cout<<Q[i]<<flush;
        if(i<rear){
            cout<< "<-" << flush;
        }
    }
    cout<<endl;
}

int main(int argc, const char * argv[]) {
    int A[] = {1, 3, 5, 7, 9};
     
        Queue q(sizeof(A)/sizeof(A[0]));
     
        // Enqueue
        for (int i=0; i<sizeof(A)/sizeof(A[0]); i++){
            q.Enqueue(A[i]);
        }
     
        // Display
        q.Display();
     
        // Overflow
        q.Enqueue(10);
     
        // Dequeue
        for (int i=0; i<sizeof(A)/sizeof(A[0]); i++){
            q.Dequeue();
        }
     
        // Underflow
        q.Dequeue();
    return 0;
}
