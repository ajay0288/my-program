#include<stdio.h>
#include<stdlib.h>

struct bst{
int data;
struct bst *left;
struct bst *right;
int height;
}*root;

int height(struct bst *n)
{
    if(n==NULL)
        return 0;
    return n->height;
}

int getbalance(struct bst *n)
{
    if(n==NULL)
        return 0;
    return height(n->left)-height(n->right);
}
int max(int a, int b)
{
    return (a > b)? a : b;
}

int rightrotate(struct bst *y)
{
    struct bst *x=y->left;
    struct bst *t2=x->right;

    x->right=y;
    y->left=t2;

    y->height=max(height(y->left),height(y->right))+1;
    x->height=max(height(x->left),height(x->right))+1;

    return x;
};

int leftrotate(struct bst *x)
{
    struct bst *y=x->right;
    struct bst *t2=y->left;

    y->left=x;
    x->right=t2;

    y->height=max(height(y->left),height(y->right))+1;
    x->height=max(height(x->left),height(x->right))+1;

    return y;
};

int create(int data)
{
    struct bst *nn=(struct bst *)malloc(sizeof(struct bst));
    nn->data=data;
    nn->left=NULL;
    nn->right=NULL;
    nn->height=1;
    return nn;
}

int insert(struct bst *root,int data)
{
if(root==NULL)
{
    return create(data);
}
else if(data<root->data)
{
    root->left=insert(root->left,data);
}
else if(data>root->data)
{
    root->right=insert(root->right,data);
}
else
{
    return root;
}
root->height=max(height(root->left),height(root->right))+1;

int balance=getbalance(root);
if(balance>1&&data<root->left->data)
    return rightrotate(root);
if(balance<-1&&data>root->right->data)
    return leftrotate(root);
if(balance>1&&data>root->left->data)
{
    root->left=leftrotate(root->left);
    return rightrotate(root);
}
if(balance<-1&&data<root->right->data)
{
    root->right=rightrotate(root->right);
    return leftrotate(root);
}
return root;
}

int min(struct bst *temp)
{
    while(temp->left!=NULL)
    {
        temp=temp->left;
    }
    return temp->data;
}

int deleter(struct bst *root,int data)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(data<root->data)
    {
        root->left=deleter(root->left,data);
    }
    else if(data>root->data)
    {
        root->right=deleter(root->right,data);
    }
    else
    {
        if(root->left==NULL)
        {
            return root->right;
        }
        if(root->right==NULL)
            return root->left;
        int key=min(root->right);
        root->data=key;
        root->right=deleter(root->right,key);
    }
    root->height=max(height(root->left),height(root->right))+1;

int balance=getbalance(root);
if(balance>1&&data<root->left->data)
    return rightrotate(root);
if(balance<-1&&data>root->right->data)
    return leftrotate(root);
if(balance>1&&data>root->left->data)
{
    root->left=leftrotate(root->left);
    return rightrotate(root);
}
if(balance<-1&&data<root->right->data)
{
    root->right=rightrotate(root->right);
    return leftrotate(root);
}
    return root;
    }

void inorder(struct bst *root)
{
    if(root==NULL)
        return;
    else
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

void main()
{
int choice,data;
printf("1.insert\n2.delete\n3.display");
while(1)
{
    printf("\nenter your choice :");
    scanf("%d",&choice);
    if(choice==1)
    {
        printf("enter the ele to be inserted\n");
        scanf("%d",&data);
        root=insert(root,data);
    }
    else if(choice==2)
    {
        printf("enter the ele to be delete\n");
        scanf("%d",&data);
        root=deleter(root,data);
    }
    else if(choice==3)
    {
        inorder(root);
    }
    else{
        break;
    }
}
}

