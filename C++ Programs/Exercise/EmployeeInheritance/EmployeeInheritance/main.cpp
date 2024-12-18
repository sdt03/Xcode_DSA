#include<iostream>

using namespace std;

class employee{
private:
    string name;
    int eid;
public:
    employee(string name, int eid){
        this->name=name;
        this->eid=eid;
    }
    int getId(){return eid;}
    
    string getName(){return name;}
};

class FTE:public employee{
private:
    int salary;
public:
    FTE(string name, int eid, int salary):employee(name, eid){
        this->salary=salary;
    }
    int getSalary(){return salary;}
};

class intern:public employee{
private:
    int stipend;
public:
    intern(string name, int eid, int stipend):employee(name, eid){
        this->stipend=stipend;
    }
    int getStipend(){return stipend;}
};

int main(){
    FTE f("Shoumik",1,100000);
    intern i("xyz",4,1000);
    
    cout<<"Salary of "<<f.getName()<<" is "<<f.getSalary()<<endl;
    cout<<"stipend of "<<i.getName()<<" is "<<i.getStipend()<<endl;
}








