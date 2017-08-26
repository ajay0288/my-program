#include<stdio.h>
int ele,i,queue[100];
int front=-1,rear=-1;
void enqueue(int data,int queue[])
{
	if(front==-1&&rear==-1)
	{
		front=rear=0;
		queue[rear]=data;
	}
	else
	queue[++rear]=data;
}
void print()
{
	while(rear>=front)
	printf("%d",queue[rear--]);
	if(rear<0)
	front=rear=-1;
}
void binary(int data)
{
	int i,x;
	if(data>0)
	{
		for(i=0;data>0;i++)
		{
			x=data%2;
			data=data/2;
			enqueue(x,queue);
		}
	}
}
void main()
{
	printf("\nenter the element : ");
	scanf("%d",&ele);
	for(i=1;i<=ele;i++)
	{
		front=rear=-1;
		binary(i);
		print();
		printf("\n");
    }
}


