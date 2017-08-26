#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *head;
    int count;
}hed[100];

struct node * create(int data);
void insert(int data,int num);
void delete(int data);


int size = 10;

int main() {
    int ch,data;
    int qcount;
    printf("Enter the number of queues::");
    scanf("%d",&qcount);
    while (1) {
        printf("\n1. Insert\n2. Delete\n");
        printf("3. Exit\n");
        printf("\nEnter your choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            {
            int key,num;
            printf("\nEnter the key value and queue number:");
            scanf("%d %d", &key,&num);
            insert(key,num);
            }
            break;

        case 2:
            {
                int key;
            printf("\nEnter the queue number to pop:");
            scanf("%d", &key);
            delete(key);
            }
            break;

        case 3:
            exit(0);
        default:
            printf("\nwrong choice\n");
            break;
        }
    }
    return 0;
}

struct node * create(int data) {
    struct node *newnode;
    newnode = (struct node *) malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

void insert(int data,int num) {
    struct node *newnode = create(data);
    if (hed[data].head==NULL) {
        hed[data].head = newnode;
        hed[data].count = 1;
        return;
    }
    newnode->next = hed[data].head;
    hed[data].head = newnode;
    hed[data].count++;
    return;
}

void delete(int data)
 {
    int flag = 0;
    struct node *t, *test;
    test = hed[data].head;
    if (test==NULL) {
        printf("stack empty");
        return;
    }
            t = test;
            test=hed[data].head;
            hed[data].head=test->next;
            printf("%d",test->data);
            hed[data].count--;
            free(test);

    }




