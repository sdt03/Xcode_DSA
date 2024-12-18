#include<iostream>

using namespace std;

class Your;
class my{
private:
    int a=10;
protected:
    int b=10;
public:
    int c=10;
    friend Your;
};

class Your{
public:
    my m;
    void fun(){
        cout<<m.a<<m.b<<m.c<<endl;
    }
};

int main(){
    Your y;
    y.fun();
}


