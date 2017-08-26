#include<stdio.h>
int stack1[100],stack2[100],top1=-1,top2=-1,max;

int push1()
{
    int ele;
    printf("enter the element to be pushed    : ");
  scanf("%d",&ele);
  if(top1<max-1)
    {
        stack1[++top1] = ele;
     printf("%d is pushed\n",ele);
     }
  else
    printf("stack is full\n");
}

int pop1()
{
    int ele;
  ele = stack1[top1];
  top1--;
  return ele;
}

void poptostack2()
{

 while(top1!=-1)
 {
     push2(pop1());
 }

}

void push2(int data)
{
    stack2[++top2]=data;
}

void dis()
{
    poptostack2();
    int i;
    if(top2==-1)
        printf("no elements in array\n");
    else
    {
        for(i=top2;i>=0;i--)
        printf("%d ",stack2[i]);
    }
}

main()
{
  printf("enter stack size\n");
  scanf("%d",&max);
  while(1)
  {
    int c;
    printf("\n1.push\n2.pop\n3.display\n4.exit\n\n");
    scanf("%d",&c);
    switch(c)
    {
      case 1:
          push1();
          break;
      case 2:
          {
          int ele=pop1();
          printf("\n%d is poped\n",ele);
          }
          break;
      case 3:
          dis();
          break;
      case 4:
          printf("\nProgram Exited\n");
          exit(0);
    }
  }
}
