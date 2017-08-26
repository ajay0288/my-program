#include<stdio.h>
  int queue[100];
int rear=-1,front=-1;
  int n,k,max,i,t;
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

void check()
{
    max=queue[front];
    i=front+k;
    t=front+1;
    while(t<i)
    {
      if(queue[t]>max)
      max=queue[t];
      t++;
    }
    front++;
    printf("%d ",max);
}
void main()
{
  printf("enter size : ");
  scanf("%d",&n);
  printf("\nenter the queue elements : \n ");
  while(rear<n-1)
  {
    enqueue();
  }
  printf("\nenter the integer:");
  scanf("%d",&k);
  while(front<=n-k)
  {
      check();

  }
}
