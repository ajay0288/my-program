#include<stdio.h>
int stack[100],top=-1,em;

void push()
{
    int ele;
    printf("enter the element to push : ");
    scanf("%d",&ele);
    stack[++top]=ele;
    em=top;
}

void pop()
{
    if(top==-1)
    {
        printf("stack is empty");
    }
    else
    {
       top--;
       em=top;
    }

}

void reverse(int i)
{
    if(i<=0)
    {
          printf("%d ",stack[i]);
          return;

    }
    else{
    reverse(i-1);
    printf("%d ",stack[i]);}

}

main()
{
    int choice;
    while(1)
    {
    printf("\n1.push\n2.pop\n3.display\n\tenter your choice : ");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        {
            push();

        }
        break;
    case 2:
        {
            pop();
        }
        break;
    case 3:
        {
            reverse(em);
        }
        break;

}
    }
}
