#include<stdio.h>
void checkqueue(int,int);
int queue[100],size,front=-1,rear=-1;
int arr[100],i,n;
void rearenqueue(int data)
{
    queue[++rear]=data;
}

void check(int arr[],int data,int k)
{
    int i,temp,flag=0;
    for(i=0;i<=rear;i++)
    {
        if(queue[i]==data)
        {
            flag=1;
            break;
        }
    }
    if(flag==0)
    {
        checkqueue(arr[k-size],data);
    }

}

void checkqueue(int data,int key)
{
    int i,temp;
    for(i=0;i<size;i++)
    {
        if(data==queue[i])
        {
            temp=key;
            key=queue[i];
            queue[i]=temp;
            break;
        }
    }
}

main()
{
printf("enter the cache size :");
scanf("%d",&size);
printf("enter the size of pages ; ");
scanf("%d",&n);
printf("enter the page numbers : \n");
for(i=0;i<n;i++)
{
    scanf("%d",&arr[i]);
    if(rear!=size-1)
    {
        rearenqueue(arr[i]);
    }
    else if(rear==size-1);
    {
        check(arr,arr[i],i);
    }
}
for(i=0;i<size;i++)
{
    printf("%d ",queue[i]);
}
}
