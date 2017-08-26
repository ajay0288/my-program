#include<stdio.h>
int arr[100];
int top1=-1,top2=-1,n;
void push1()
{
    if(top1==top2-1)
    {
        printf("stack full/n");
    }
    else
    {
        int ele;
            printf("enter the element to push : ");
            scanf("%d",&ele);
        arr[++top1]=ele;
    }
}


void push2()
{
    if(top2==top1+1)
    {
        printf("stack full/n");
    }
    else
    {
        int ele;
            printf("enter the element to push : ");
            scanf("%d",&ele);
            arr[--top2]=ele;
    }


}

int pop1()
{
    int ele;
    if(top1==-1)
    {
        printf("stack underflow\n");
    }
    else
    {
        ele=arr[top1];
        top1--;
         printf("the popped element is : %d\n",ele);
    }
}

int pop2()
{
    int ele;
    if(top2==n+1)
    {
        printf("\nstack underflow\n");
    }
    else
    {
        ele=arr[top2];
        top2++;
        printf("the popped element is : %d\n",ele);
    }
}

main()
{
    int choice;
    printf("enter element size : ");
    scanf("%d",&n);
    top2=n+1;
    while(1)
    {
    printf("\n1.push1\n2.push2\n3.pop1\n4.pop2\n\tenter your choice : ");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        {
            push1();

        }
        break;
    case 2:
        {
            push2();
        }
        break;
    case 3:
        {
            pop1();
        }
        break;
     case 4:
        {
            pop2();
        }
        break;
    }
    }

}
