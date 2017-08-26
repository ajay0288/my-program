#include<stdio.h>
int stack[100],top=-1;
void push(int data)
{
    if(top==99)
    {
        return;
    }
    else
    stack[++top]=data;
}

void pop()
{
    if(top==-1)
    {
        return;
    }
    else
    top--;
}

void stacksort(int stack[],int s,int e)
{
    int mid;
    int pivot;
    if(s>e)
      return;
     else
     {
        int i,temp;
        int piv=stack[e];
         int index=s;
          for(i=s;i<e;i++)
           {
             if(stack[i]<=piv)
            {
            temp=stack[i];
            stack[i]=stack[index];
            stack[index]=temp;
            index++;
            }
    }

            temp=stack[index];
            stack[index]=stack[e];
            stack[e]=temp;
        mid=index;
        stacksort(stack,s,mid-1);
        stacksort(stack,mid+1,e);

}
}

void print(int res)
{
    if(res==-1)
        return res;
    else
    {
        res--;
        print(res);
        printf("%d ",stack[res+1]);
    }
}
main()
{
    int choice;
    while(1)
    {
        printf("\n1push\n2.pop\n3.display\nenter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            {
            int data;
            printf("enter the data tobe insert : ");
            scanf("%d",&data);
            push(data);
            }
            break;
        case 2:
            pop();
            break;
        case 3:
            {
                int res=top;
            stacksort(stack,0,top);
            print(res);
            }
            break;

        }
    }
}
