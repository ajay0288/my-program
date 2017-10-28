#include<stdio.h>
#include<stdlib.h>

struct bst{
int data;
struct bst *left;
struct bst *right;
}*root;

int create(int data)
{
    struct bst *nn=(struct bst *)malloc(sizeof(struct bst));
    nn->data=data;
    nn->left=NULL;
    nn->right=NULL;
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
