#include<iostream>

using namespace std;

class shape{
public:
    virtual float area()=0;
    virtual float perimeter()=0;
};

class Rectangle:public shape{
private:
    float length;
    float breadth;
public:
    Rectangle(int l=1, int b=1){
        length=l;
        breadth=b;
    }
    float area(){return length*breadth;}
    float perimeter(){return 2*(length+breadth);}
};

class Circle:public shape
{
private:
    float radius;
public:
    Circle(float r){
        radius=r;
    }
    float area(){return 3.14*radius*radius;}
    float perimeter(){return 2*3.14*radius;}
    
};
    
int main()
{
    shape *s=new Rectangle(10,5);
        
    cout<<"Area of Rectangle "<<s->area()<<endl;
    cout<<"Perimeter of Rectangle "<<s->perimeter()<<endl;

    s=new Circle(10);
        
    cout<<"Area of Circle "<<s->area()<<endl;
    cout<<"Perimeter of Circle "<<s->perimeter()<<endl;

}
