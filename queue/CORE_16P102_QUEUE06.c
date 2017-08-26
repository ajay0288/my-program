#include<stdio.h>
struct node{
	int data;
	struct node *next;
	struct node *head;
}queue[100];
int choose(int choice)
{
	int num,data;
	switch(choice)
	{
		case 1:
		    printf("Enter the input value:");
            scanf("%d",&data);
            printf("Enter the Queue number:");
            scanf("%d",&num);
            enqueue(data,num);
            break;
		case 2:
		    printf("Enter the queue number to be dequed");
            scanf("%d",&num);
            dequeue(num);
            return 1;
		default:
		    return 0;
	}
}
void enqueue(int data,int n)
{
	struct node *newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data=data;
	newnode->next=NULL;
	if(queue[n].head==NULL)
	{
		queue[n].head=newnode;
	}
	else
	{
	struct node *temp;
	temp=queue[n].head;
	while(temp->next!=NULL)
	     temp=temp->next;
	temp->next=newnode;
	}

}
void dequeue(int n)
{
	if(queue[n].head==NULL)
	printf("\nQueue is empty");
	else
	{
		struct node *temp=queue[n].head;
		printf("\ndequeued element from queue %d is %d",n,temp->data);
		if(temp->next==NULL)
		{
			queue[n].head=NULL;
		}
		else
		{
			queue[n].head=temp->next;
		}
	}
}
void main()
{
	int k,i,choice,z=1;
	printf("Enter the number of Queue:");
	scanf("%d",&k);
	for(i=0;i<k;i++)
	queue[i].head=NULL;
	while(z)
	{
		printf("\nPress 1 for ENQUEUE\npress 2 for DEQUEUE\nPress 0 to EXIT\nEnter your choice  ;");
	    scanf("%d",&choice);
	    z=choose(choice);
	}

}

