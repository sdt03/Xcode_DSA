#include<iostream>

using namespace std;

class Student{
private:
    string name;
    int roll;
    int Pmarks;
    int Cmarks;
    int Mmarks;
    
public:
    Student(string name, int roll, int p, int c, int m){
        this->name=name;
        this->roll=roll;
        Pmarks=p;
        Cmarks=c;
        Mmarks=m;
    }
    int total(){
        return Mmarks+Pmarks+Cmarks;
    }
    char Grade(){
        float average=total()/3;
        if(average>80){
            return 'A';
        }
        else if(average>60){
            return 'B';
        }
        else if(average>=40){
            return 'C';
        }
        return 'D';
    }
};

int main(){
    int roll;
    string name;
    int p,c,m;
    cout<<"Enter name of the student: ";
    cin>>name;
    cout<<"Enter roll no of the student: ";
    cin>>roll;
    cout<<"Enter marks for p,c,m: ";
    cin>>p>>c>>m;
    Student s(name,roll,p,c,m);
    cout<<"Total marks: "<<s.total()<<endl;
    cout<<"Grade: "<<s.Grade()<<endl;
}
