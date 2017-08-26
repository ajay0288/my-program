#include<stdio.h>
#include<stdlib.h>
struct avl
{
    int key;
    struct avl *left;
    struct avl *right;
    int height;
};
int max(int a, int b);

int height(struct avl *nnode)
{
    if (nnode == NULL)
        return 0;
    return nnode->height;
}

int max(int a, int b)
{
    if (a>b)
    {
        return a;
    }
    else
        return b;
}


struct avl* newnode(int key)
{
    struct avl* node = (struct avl*)
                        malloc(sizeof(struct avl));
    node->key   = key;
    node->left   = NULL;
    node->right  = NULL;
    node->height = 1;
    return(node);
}

struct avl *rightRotate(struct avl *y)
{
    struct avl *x = y->left;
    struct avl *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right))+1;
    x->height = max(height(x->left), height(x->right))+1;

    return x;
}


struct avl *leftRotate(struct avl *x)
{
    struct avl *y = x->right;
    struct avl *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right))+1;
    y->height = max(height(y->left), height(y->right))+1;

    return y;
}

int cbalance(struct avl *nnode)
{
    if (nnode == NULL)
        return 0;
    else
    return height(nnode->left) - height(nnode->right);
}

struct avl* insert(struct avl* node, int key)
{

    if (node == NULL)
        return(newnode(key));

    if (key < node->key)
        node->left  = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;
    node->height = 1 + max(height(node->left),
                           height(node->right));

    int bal = cbalance(node);


    if (bal> 1 && key < node->left->key)
        return rightRotate(node);

    if (bal < -1 && key > node->right->key)
        return leftRotate(node);

    if (bal > 1 && key > node->left->key)
    {
        node->left =  leftRotate(node->left);
        return rightRotate(node);
    }

    if (bal < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}


struct avl * min(struct avl* node)
{
    struct avl* current = node;

    while (current->left != NULL)
        current = current->left;

    return current;
}

struct avl* deletenode(struct avl* root, int key)
{


    if (root == NULL)
        return root;

    if ( key < root->key )
        root->left = deletenode(root->left, key);

    else if( key > root->key )
        root->right = deletenode(root->right, key);

    else
    {
        if( (root->left == NULL) || (root->right == NULL) )
        {
            struct avl *temp;
            if(root->left==NULL)
               temp=root->right;
            else
               temp=root->left;

            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else
             *root = *temp;

             free(temp);
        }
        else
        {
            struct avl* temp = min(root->right);
            root->key = temp->key;
            root->right = deletenode(root->right, temp->key);
        }
    }

    if (root == NULL)
      return root;

    root->height = 1 + max(height(root->left),
                           height(root->right));

    int balance = cbalance(root);

    if (balance > 1 && cbalance(root->left) >= 0)
        return rightRotate(root);

    if (balance > 1 && cbalance(root->left) < 0)
    {
        root->left =  leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && cbalance(root->right) <= 0)
        return leftRotate(root);

    if (balance < -1 && cbalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void pre(struct avl *root)
{
    if(root != NULL)
    {
        printf("%d ", root->key);
        pre(root->left);
        pre(root->right);
    }
}
void in(struct avl *root)
{
    if(root != NULL)
    {
        in(root->left);
        printf("%d ", root->key);
        in(root->right);
    }
}

void post(struct avl *root)
{
    if(root != NULL)
    {
        post(root->left);
        post(root->right);
        printf("%d ", root->key);

    }
}

int main()
{
    int i,ch;
    struct avl *root = NULL;
    while(1)
    {
        printf("\n\n1.insert\n2.delete\n3.display\n\n\tenter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                {
                    int key;
                    printf("\nenter the element to insert : ");
                    scanf("%d",&key);
                    root = insert(root,key);
                }
                break;
            case 2:
                {
                    int key;
                    printf("\nenter the element to delete : ");
                    scanf("%d",&key);
                      root = deletenode(root,key);

                }
                break;
            case 3:
                {
                    printf("\nPREORDER TRAVERSAL\n");
                    pre(root);
                    printf("\nINORDER TRAVERSAL\n");
                    in(root);
                    printf("\nPOSTORDER TRAVERSAL\n");
                    post(root);

                }
                break;
            default:
                printf("\nwrong choice\n");
                break;
        }

    }

    return 0;
}
