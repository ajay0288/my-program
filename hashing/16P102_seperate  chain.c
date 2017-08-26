#include <stdio.h>
#include <stdlib.h>

int size = 10;

struct node {
    int data;
    struct node *next;
    struct node *head;
    int count;
}hash[10];



struct node * create(int data) {
    struct node *newnode;
    newnode = (struct node *) malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

void insert(int data) {
    int index = (data % size)%size;
    struct node *newnode = create(data);
    if (hash[index].head==NULL) {
        hash[index].head = newnode;
        hash[index].count = 1;
        return;
    }
    newnode->next = hash[index].head;
    hash[index].head = newnode;
    hash[index].count++;
    return;
}

void delete(int data)
 {
    int index = (data % size)%size, flag = 0;
    struct node *temp, *test;
    test = hash[index].head;
    if (test==NULL) {
        printf("Given data is not present\n");
        return;
    }
    temp = test;
    while (test != NULL)
        {
        if (test->data == data)
         {
            flag = 1;
            if (test == hash[index].head)
                hash[index].head = test->next;
            else
            {
                temp->next = test->next;
                test->next=NULL;
            }
            hash[index].count--;
            free(test);
            break;
        }
        temp = test;
        test = test->next;
    }
    if (flag)
        printf("Data deleted successfully\n");
    else
        printf("Given data is not present\n");
    return;
}


void sort()
{
    int swap,i,k;
    struct node *sort;
    struct node *temp;
    for(i=0;i<size;i++)
    {
        sort=hash[i].head;

        while(sort!=NULL)
        {
            temp=sort->next;
            while(temp!=NULL)
            {
                if(temp->data<sort->data)
                {
                    swap=sort->data;
                    sort->data=temp->data;
                    temp->data=swap;
                }
                temp=temp->next;
            }
            sort=sort->next;
        }
    }
}


void display() {
    sort();
    struct node *print;
    int i;
    for (i = 0; i < size; i++)
        {
        print = hash[i].head;
        printf("index = %d   no of elements = %d",i,hash[i].count);
        if(hash[i].count>=1)
        {
        printf("\t\t%d = ", i);
        while (print != NULL) {
            printf("%d -> ", print->data);
            print = print->next;
        }
        printf("null");
        }
        printf("\n\n");
}
}

int main() {
    int ch,data;
    while (1) {
        printf("\n1. Insert\n2. Delete\n");
        printf("3. Display\n4. Exit\n");
        printf("\n\tEnter your choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            {
            int key;
            printf("\nEnter the key value:");
            scanf("%d", &key);
            insert(key);
            }
            break;

        case 2:
            {
                int key;
            printf("\nEnter the key to delete:");
            scanf("%d", &key);
            delete(key);
            }
            break;

        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("\nwrong choice\n");
            break;
        }
    }
    return 0;
}

