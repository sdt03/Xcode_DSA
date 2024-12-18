#include<iostream>

using namespace std;

class Rectangle{
private:
    int length;
    int breadth;
public:
    //Constructor
    Rectangle(int l=1,int b=1){
        setLength(l);
        setBreadth(b);
    }
    //copy constructor
    Rectangle(Rectangle &r){
        length=r.length;
        breadth=r.breadth;
    }
    
    void setLength(int l){
        if(l>=0)
            length=l;
        else{
            cout<<"Length cannot be negative\n"<<endl;
            length=0;
        }
    }
    void setBreadth(int b){
        if(b>=0)
            breadth=b;
        else{
            cout<<"Breadth cannot be negative\n"<<endl;
            breadth=0;
        }
    }
    
    int getLength(){
        return length;
    }
    
    int getBreadth(){
        return breadth;
    }
    
    int area(){
        return length*breadth;
    }
    
    int perimeter(){
        return 2*(length+breadth);
    }
};

//inheritance
class cuboid:public Rectangle{
private:
    int height;
public:
    cuboid(int h){
        height=h;
    }
    int getheight(){return height;}
    void setheight(int h){height=h;}
    int volume(){return getLength()*getBreadth()*getheight();}
};

int main(){
    /*Rectangle r1,r2;
    r1.length=10;
    r1.breadth=5;
    cout<<"Area is "<<r1.area()<<endl;
    cout<<"Perimeter is "<<r1.perimeter()<<endl;
    
    Rectangle *p=new Rectangle();
    p->setLength(10);
    p->setBreadth(5);
    cout<<p->area()<<endl;
    cout<<p->perimeter()<<endl;*/
    cuboid c(5);
    c.setLength(10);
    c.setBreadth(7);
    cout<<"Volume = "<<c.volume()<<endl;
    return 0;
}
