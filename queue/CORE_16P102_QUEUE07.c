#include<stdio.h>
int queue[100],rear=-1,front=-1;
void enqueue()
{
    if(rear==-1&&front==-1)
    {
        front=0;
        scanf("%d",&queue[++rear]);
    }
    else
        scanf("%d",&queue[++rear]);
}
void dequeue()
{
        printf("%d",queue[rear--]);
}
main()
{
    int num;
    printf("enter the queue size :");
    scanf("%d",&num);
    while(rear<num-1)
    {
        enqueue();
    }

    while(rear>=0)
    {
        dequeue();
    }
}
