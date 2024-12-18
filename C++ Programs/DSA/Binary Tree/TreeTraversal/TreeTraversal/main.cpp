#include <iostream>
#include<stack>
#include<queue>

using namespace std;

class node{
public:
    node* lchild;
    int data;
    node* rchild;
    node(){};
    node(int data);
};

node::node(int data){
    lchild=nullptr;
    this->data=data;
    rchild=nullptr;
}

class Tree{
private:
    node* root;
public:
    Tree();
    void CreateTree();
    void Preorder(node *p);
    void Preorder(){Preorder(root);}
    void postorder(node *p);
    void postorder(){postorder(root);}
    void inorder(node* p);
    void inorder(){inorder(root);}
    void levelorder(node* p);
    void levelorder(){levelorder(root);}
    int height(node* p);
    int height(){return height(root);}
    void Ipreorder(node* p);
    void Ipreorder(){Ipreorder(root);}
    void Ipostorder(node* p);
    void Ipostorder(){Ipostorder(root);}
    void Iinorder(node* p);
    void Iinorder(){Iinorder(root);}
    node* generatefromtraversal(int inorder[], int preorder[], int instart, int inend);
};

Tree::Tree(){
    root=nullptr;
}

void Tree::CreateTree(){
    node* p;
    node* t;
    int x;
    queue<node*> q;
    
    root=new node;
    cout<<"Enter the root element: "<<flush;
    cin>>x;
    root->data=x;
    root->lchild=root->rchild=nullptr;
    q.emplace(root);
    
    while(!q.empty()){
        p=q.front();
        q.pop();
        
        cout<<"Enter left child of: "<<p->data<<flush;
        cin>>x;
        if(x!=-1){
            t=new node;
            t->data=x;
            t->lchild=t->rchild=nullptr;
            p->lchild=t;
            q.emplace(t);
        }
        cout<<"Enter right child of: "<<p->data<<flush;
        cin>>x;
        if(x!=-1){
            t=new node;
            t->data=x;
            t->lchild=t->rchild=nullptr;
            p->rchild=t;
            q.emplace(t);
        }
    }
}

void Tree::Preorder(node *p){
    if(p){
        cout<<p->data<<", "<<flush;
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}

void Tree::postorder(node *p){
    if(p){
        postorder(p->lchild);
        cout<<p->data<<", "<<flush;
        postorder(p->rchild);
    }
}

void Tree::inorder(node *p){
    if(p){
        inorder(p->lchild);
        inorder(p->rchild);
        cout<<p->data<<", "<<flush;
    }
}

void Tree::Ipreorder(node *p){
    stack<node*> st;
    while(p!=nullptr||!st.empty()){
        if(p!=nullptr){
            cout<<p->data<<", "<<flush;
            st.emplace(p);
            p=p->lchild;
        }
        else{
            p=st.top();
            st.pop();
            p=p->rchild;
        }
    }
    cout<<endl;
}

void Tree::Ipostorder(node *p){
    stack<node*> st;
    while(p!=nullptr||!st.empty()){
        if(p!=nullptr){
            st.emplace(p);
            p=p->lchild;
        }
        else{
            p=st.top();
            st.pop();
            cout<<p->data<<", "<<flush;
            p=p->rchild;
        }
    }
}

void Tree::levelorder(node *p){
    queue<node*> q;
    cout<<p->data<<", "<<flush;
    q.emplace(p);
    
    while(!q.empty()){
        p=q.front();
        q.pop();
        
        if(p->lchild){
            cout<<p->lchild->data<<", "<<flush;
            q.emplace(p->lchild);
        }
        else if(p->rchild){
            cout<<p->rchild->data<<", "<<flush;
            q.emplace(p->rchild);
        }
        
    }
}

int Tree::height(node *p){
    int x=0,y=0;
    if(p==NULL){
        return 0;
    }
    x=height(p->lchild);
    y=height(p->rchild);
    
    if(x>y){
        return x+1;
    }
    else{
        return y+1;
    }
}

int searchInorder(int inArray[], int instart, int inend, int data){
    for(int i=instart; i<=inend; i++){
        if(inArray[i]==data)
            return i;
    }
    return -1;
}

node* Tree::generatefromtraversal(int *inorder,int *preorder, int instart, int inend){
    static int preIndex=0;
    if(instart>inend){
        return nullptr;
    }
    
    node* Node = new node(preorder[preIndex++]);
    
    if(instart==inend)
        return Node;
    
    int spiltIndex=searchInorder(inorder, instart, inend, Node->data);
    Node->lchild=generatefromtraversal(inorder, preorder, instart, spiltIndex-1);
    Node->rchild=generatefromtraversal(inorder, preorder, spiltIndex+1, inend);
    
    return Node;
}

int main(int argc, const char * argv[]) {
    Tree bt;
    /*bt.CreateTree();
     cout<<endl;
     
     cout<<"Preorder: "<<flush;
     bt.Preorder();
     cout<<endl;
     
     cout<<"Postorder: "<<flush;
     bt.postorder();
     cout<<endl;
     
     cout<<"Inorder: "<<flush;
     bt.Preorder();
     cout<<endl;*/
    
    int preorder[]={4,7,9,6,3,2,5,8,1};
    int inorder[]={7,6,9,3,4,5,8,2,1};
    
    node* T = bt.generatefromtraversal(inorder, preorder, 0, sizeof(inorder)/sizeof(inorder[0])-1);
    bt.Preorder(T);
    
    return 0;
}
