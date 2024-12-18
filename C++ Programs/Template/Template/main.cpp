#include <iostream>

using namespace std;

template <class T>
class Stack{
private:
    T *stk;
    int top;
    int size;
public:
    Stack(int s){
        size=s;
        top=-1;
        stk = new T[size];
    }
    void push(T x);
    T pop();
};

template <class T>
    void Stack<T>::push(T x){
        if(top==size-1)
            cout<<"Stack is full"<<endl;
        else{
            stk[top++]=x;
        }
    }

template <class T>
T Stack<T>::pop(){
    int x=0;
    if(top==-1)
        cout<<"Stack is empty"<<endl;
    else{
        x=stk[top];
        top--;
    }
    return x;
}

int main(){
    Stack<int> s(10);
    
    s.push(3);
    s.push(10);
    s.push(17);
    s.push(15);
}
