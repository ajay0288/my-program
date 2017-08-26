#include<stdio.h>
int queue[100],front=-1,rear=-1;
  int n,k,max,min,i,t,sum=0;
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
checkmax()
{
    max=queue[front];
    i=front+k;
    t=front+1;
    while(t<i)
    {
      if(queue[t]>max)
      max=queue[t];
      if(queue[t]<min)
      min=queue[t];
      t++;
    }
    sum=sum+(min+max);
    front++;
}
void main()
{

  printf("enter size : ");
  scanf("%d",&n);
  while(rear<n-1)
  {
    enqueue();
  }
  printf("\nenter the subarray size : ");
  scanf("%d",&k);
  while(front<=n-k)
  {
  checkmax();
  }
  printf("%d",sum);
}
