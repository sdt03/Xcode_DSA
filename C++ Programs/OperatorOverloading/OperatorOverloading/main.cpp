#include<iostream>

using namespace std;

class Complex{
private:
    int real;
    int img;
public:
    Complex(int r=0, int i=0){
        real=r;
        img=i;
    }
    
    void Display(){
        cout<<real << "+i"<<img<<endl;
    }
    /*Complex operator+(Complex c){
        Complex temp;
        temp.real=real + c.real;
        temp.img=img+c.img;
        return temp;
    }*/
    friend Complex operator+(Complex c1, Complex c2);
};

Complex operator+(Complex c1, Complex c2){
    Complex temp;
    temp.real=c1.real + c2.real;
    temp.img=c1.img+c2.img;
    return temp;
}

int main(){
    Complex c1(5,3),c2(10,5);
    Complex c3=c1+c2;
    
    c3.Display();
    /*c1.real=5;c1.img=3;
    c2.real=10;c2.img=4;
    c3=c1+c2;
    cout<<c3.real << "+i"<<c3.img<<endl;*/
    
}
