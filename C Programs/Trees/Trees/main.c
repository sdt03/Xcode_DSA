#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *rchild;
    struct Node *lchild;
};
struct Node *createnode(int data)
{
    struct Node *t=(struct Node*)malloc(sizeof(struct Node));
    t->data=data;
    t->lchild=t->rchild=NULL;
    return t;
}

struct Node *insertnode(struct Node *root, int data){
    if(root==NULL){
        return createnode(data);
    }
    else if(data<=root->data){
        root->lchild=insertnode(root->lchild, data);
    }
    else if(data>root->data){
        root->rchild=insertnode(root->rchild,data);
    }
    return root;
}

void preorderTraversal(struct Node *root){
    if(root!=NULL){
        printf("%d ", root->data);
        preorderTraversal(root->lchild);
        preorderTraversal(root->rchild);
    }
}

void inorderTraversal(struct Node *root){
    if(root!=NULL){
        inorderTraversal(root->lchild);
        printf("%d ",root->data);
        inorderTraversal(root->rchild);
    }
}

void postorderTraversal(struct Node *root){
    if(root!=NULL){
        postorderTraversal(root->lchild);
        postorderTraversal(root->rchild);
        printf("%d ",root->data);
    }
}

int Count(struct Node *root){
    int x;
    int y;
    if(root!=NULL){
        x=Count(root->lchild);
        y=Count(root->rchild);
        return x+y+1;
    }
    return 0;
}

int sumNode(struct Node *root){
    int sum=0;
    int x,y;
    if(root!=NULL){
        x=sumNode(root->lchild);
        y=sumNode(root->rchild);
        return sum = root->data+x+y;
    }
    return 0;
}

int Height(struct Node *root){
    int x,y;
    if(root!=NULL){
        x=Count(root->lchild);
        y=Count(root->rchild);
        if(x>y)
            return x+1;
        else
            return y+1;
    }
    return 0;
}

int main()
{
    struct Node *root=NULL;
    int i;
    int n,data;
    printf("Enter the no of Nodes \n");
    scanf("%d",&n);
    printf("Enter elements \n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&data);
        root=insertnode(root,data);
    }
    printf("Inorder traversal \n");
    inorderTraversal(root);
    printf("\n");
    printf("Preorder traversal \n");
    preorderTraversal(root);
    printf("\n");
    printf("Postorder traversal \n");
    postorderTraversal(root);
    printf("\n");
    
    printf("Sum of all nodes is: %d\n",sumNode(root));
    printf("%d ",Count(root));
    return 0;
}
