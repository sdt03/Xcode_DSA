#include<iostream>
#include<fstream>
#include<vector>

using namespace std;

class List{
private:
    string name;
    float price;
    int qty;
public:
    List(){}
    List(string n, float p, int q){
        name=n;
        price=p;
        qty=q;
    }
    friend ifstream & operator>>(ifstream &fis, List &i);
    friend ofstream & operator<<(ofstream &fos, List &i);
    friend ostream & operator<<(ostream &os, List &i);
};

int main(){
    int n;
    string name;
    float price;
    int qty;
    
    cout<<"Enter no of items: ";
    cin>>n;
    
    vector<List *> list;
    cout<<"Enter all the items: "<<endl;
    
    for(int i=0;i<n;i++){
        cout<<"Enter "<<n+1<<" Item name, price, quantity ";
        cin>>name>>price>>qty;
        list.push_back(new List(name,price,qty));
    }
    ofstream fos("Items.txt");
    vector<List *>::iterator itr;
    for(itr=list.begin();itr!=list.end();itr++){
        fos<<**itr;
    }
    List item;
    ifstream fis("Items.txt");
    for(int i=0;i<3;i++){
        fis>>item;  
        cout<<"Item "<<i<<endl<<item<<endl;
    }
}

ofstream & operator<<(ofstream &fos, List &i){
    fos<<i.name<<endl<<i.price<<endl<<i.qty<<endl;
    return fos;
}
ifstream & operator>>(ifstream &fis, List &i){
    fis>>i.name>>i.price>>i.qty;
    return fis;
}
ostream & operator<<(ostream &os, List &i){
    os<<i.name<<endl<<i.price<<endl<<i.qty<<endl;
    return os;
}
