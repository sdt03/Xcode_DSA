#include<stdio.h>
#include<stdlib.h>
#define size 100
struct node{
    int data;
    struct node *left;
    struct node *right;
   int flg;
};
struct stack{
    struct node *arr[size];
    int top;
};
struct stack s;
int isEmpty()
{
    if(s.top==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

struct node *createnode(int data)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->flg=0;
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}

struct node *insert(struct node *root,int data)
{
    if(root==NULL)
    {
        return createnode(data);
    }
    if(data<=root->data)
    {
        root->left=insert(root->left,data);
    }
    else if(data>root->data)
    {
        root->right=insert(root->right,data);
    }
    return root;
    
}

void push(struct node *temp)
{
    if(s.top==size-1)
    {
        return;
    }
    else
    {
        s.arr[++s.top]=temp;
    }
}


struct node *pop()
{
    
    if(s.top==-1)
    {
        return NULL;
    }
    else
    {
        return s.arr[s.top--];
    }
}

void Clear()
{
    if(s.top==-1)
    {
        return;
    }
    else
    {
        while(s.top!=-1)
        {
            s.top--;
        }
    }
}

void Ipreorder(struct node *root)
{
    struct node *temp=root;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        push(temp);
        temp=temp->left;
    }
    
    while(!isEmpty())
    {
        temp=pop();
        temp=temp->right;
        while(temp!=NULL)
        {
            printf("%d ",temp->data);
            push(temp);
            temp=temp->left;
        }
    }
    
}


void inorder(struct node *root)
{
    struct node *temp=root;
    while(temp!=NULL)
    {
        push(temp);
        temp=temp->left;
    }
    while(!isEmpty())
    {
        temp=pop();
        printf("%d ",temp->data);
        temp=temp->right;
        while(temp!=NULL)
        {
            push(temp);
            temp=temp->left;
        }
    }
}

int CountLeaf(struct node *root){
    int x,y;
    if(root!=NULL){
        x=CountLeaf(root->left);
        y=CountLeaf(root->right);
       
        if(root->left==NULL && root->right==NULL)//for leaf node
        {
            return x+y+1;
        }
        else return x+y;
        }
    return 0;
}

int CountDeg1(struct node *root){
    int x,y;
    if(root!=NULL){
        x=CountLeaf(root->left);
        y=CountLeaf(root->right);
        
        if(root->left!=NULL || root->right!=NULL){
            return x+y+1;
        }
        else{
            return x+y;
        }
    }
    return 0;
}

int CountDeg2(struct node *root){
    int x,y;
    if(root!=NULL){
        x=CountLeaf(root->left);
        y=CountLeaf(root->right);
        
        if(root->left && root->right){
            return x+y;
        }
        else{
            return 1;
        }
    }
    return 0;
}

int height(struct node *root){
    int x=0;
    int y=0;
    if(root==0){
        return 0;
    }
    x=height(root->left);
    y=height(root->right);
    if(x>y) return x+1;
    else return y+1;
}

int SumofTree(struct node *root){
    int sum;
    int sumLeft;
    int sumRight;
    sum=sumLeft=sumRight=0;
    if(root==NULL) return 0;
    else{
        if(root->left!=NULL){
            sumLeft=SumofTree(root->left);
        }
        if(root->right!=NULL){
            sumRight=SumofTree(root->right);
        }
        sum = root->data+sumLeft+sumRight;
    }
    return sum;
}

int Duplicate(struct node *root, int key){
    int x=-1;
    
    return x;
}

int main()
{
    s.top = -1;
    int n;
    printf("Enter the number of nodes in the BST:");
    scanf("%d", &n);
    printf("Enter the data of nodes:");
    struct node *root = NULL;
    for (int i = 0; i < n; i++)
    {
        int data;
        scanf("%d", &data);
        root = insert(root, data);
    }
    printf("Pre-Order Traversal:\n");
    Ipreorder(root);
    Clear();
    printf("\nno of leaf nodes are: %d\n",CountLeaf(root));
    printf("\nNo of nodes with deg1 are: %d\n",CountDeg1(root));
    printf("\nNo of nodes with deg2 are: %d\n",CountDeg2(root));
    printf("height of the tree is: %d\n",height(root));
    printf("Sum of the binary Tree is : %d\n",SumofTree(root));
    return 0;
}
