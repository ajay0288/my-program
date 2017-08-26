#include<stdio.h>
int stack[100],max;
int top=-1;
int push()
{
    int ele;
    printf("enter the element to be pushed    : ");
  scanf("%d",&ele);
  if(top<max-1)
    {
        stack[++top] = ele;
     printf("%d is pushed\n",ele);
     }
  else
    printf("stack is full\n");
}

int pop()
{
    int ele;
  ele = stack[top];
  top--;
  printf("%d is poped\n",ele);
}

int find()
{
    int mid;
  mid = top/2;
  printf("%d is middle element\n",stack[mid]);
}

int del()
{
    int i,mid,c;
  mid=top/2;
 for ( c = mid - 1 ; c < top ; c++ )
        stack[c] = stack[c+1];
    printf("\n%d is deleted\n ",stack[mid]);
}

void dis()
{
    int i;
    if(top==-1)
        printf("no elements in array\n");
    else
    {
        for(i=0;i<=top;i++)
        printf("%d ",stack[i]);
    }
}

main()
{
  printf("enter stack size\n");
  scanf("%d",&max);
  while(1)
  {
    int c;
    printf("\n1.push\n2.pop\n3.find middle\n4.delete middle\n5.display\n6.exit\n");
    scanf("%d",&c);
    switch(c)
    {
      case 1:
          push();
          break;
      case 2:
          pop();
          break;
      case 3:
          find();
          break;
      case 4:
          del();
          break;
      case 5:
          dis();
          break;
      case 6:
          printf("Program Exited");
          exit(0);
    }
  }

}
