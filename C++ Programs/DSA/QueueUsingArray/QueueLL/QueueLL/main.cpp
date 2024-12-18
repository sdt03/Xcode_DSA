#include <iostream>

using namespace std;

class Node{
public:
    int data;
    Node* next;
};

class Queue{
private:
    Node* front;
    Node* rear;
public:
    Queue();
    ~Queue();
    void enqueue(int x);
    int dequeue();
    bool isFull();
    bool isEmpty();
    void Display();
};

Queue::Queue(){
    front=nullptr;
    rear=nullptr;
}

bool Queue::isEmpty(){
    if(front==rear)
        return true;
    else
        return false;
}

void Queue::enqueue(int x){
    Node* t = new Node;
    if(t==nullptr){
        cout<<"Queue Overflow"<<endl;
    }
    else{
        t->data=x;
        t->next=nullptr;
        if(front==nullptr){
            front=rear=t;
        }
        else{
            rear->next=t;
            rear=t;
        }
    }
}


int Queue::dequeue(){
    int x=-1;
    Node* p;
    if(isEmpty()){
        cout<<"Queue underflown"<<endl;
    }
    else{
        p=front;
        front=front->next;
        x=p->data;
        delete p;
    }
    return x;
}


Queue::~Queue(){
    Node* p=front;
    while(front){
        front=front->next;
        delete p;
        p=front;
    }
}

void Queue::Display(){
    Node* p=front;
    while(p){
        cout<<p->data<<flush;
        p=p->next;
        if(p!=nullptr){
            cout<<"<-"<<flush;
        }
    }
    cout<<endl;
}


int main(int argc, const char * argv[]) {
    int A[] = {1, 3, 5, 7, 9};
    
       Queue q;
    
       for (int i=0; i<sizeof(A)/sizeof(A[0]); i++){
           q.enqueue(A[i]);
       }
    
       q.Display();
    
       for (int i=0; i<sizeof(A)/sizeof(A[0]); i++){
           q.dequeue();
       }
       q.dequeue();
    return 0;
}
