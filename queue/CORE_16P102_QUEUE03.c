#include<stdio.h>
int queue[100],front=-1,rear=-1,size;

void rearenqueue()
{ int p;
    if(rear==-1&&front==-1)
    {

        printf("\nEnter the element to be inserted:");
        scanf("%d",&p);
        front=0;
        queue[++rear]=p;
        printf("\n%d is inserted\n",queue[rear]);
    }
    else if((rear+1)%(size)==front)
    {
        printf("cant be insert \n");
    }
    else
    {
        printf("\nEnter the element to be inserted:");
        scanf("%d",&p);
        queue[(++rear)%(size)]=p;
        printf("\n%d is inserted\n",queue[(rear)%(size)]);
    }
}
void reardequeue()
{
if(rear==-1)
    {
        printf("\nele can't be deleted\n");
    }
else if(rear==front)
    {
        printf("\n%d is deleted\n",queue[rear]);
        rear=-1;
        front=-1;
    }
else
    {
        printf("\n%d is deleted\n",queue[rear]);
        rear=(--rear)%(size);
    }
}
void frontenqueue()
{
  if(rear==-1&&front==-1)
  {
      int n;
      printf("\nEnter the ele to be insert:");
      scanf("%d",&n);
      rear=0;
      front=0;
      queue[front]=n;
      printf("\n%d is inserted\n",queue[front]);
  }
  else if((front-1)%(size)==rear||front==0)
  {
      printf("\nelement cant be inserted\n");
  }
  else
  {
      int n;
      printf("\nEnter the ele to be insert:");
      scanf("%d",&n);
    queue[--front%(size)]=n;
    printf("\n%d is inserted\n",queue[front%(size)]);
  }

}
void frontdequeue()
{
    if(front==-1)
    {
        printf("\nele can't be deleted\n");
    }
    else if(front==rear)
    {
        printf("\n%d is deleted\n",queue[front]);
        rear=-1;
        front=-1;
    }
    else
    {
        printf("\n%d is deleted\n",queue[front]);
        front=(++front)%(size);
    }
}
void main()
{
    printf("\nenter size : ");
    scanf("%d",&size);
    int ch;

    while(1)
    {
        printf("\n1.frontenqueue\n2.frontdequeue\n3.rearenqueue\n4.reardequeue\nenter your choice :");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                {

                frontenqueue();
                }
                break;
            case 2:
                   frontdequeue();
                   break;
            case 3:
                  rearenqueue();
                   break;
            case 4:
                reardequeue();
                break;
}
    }
}

