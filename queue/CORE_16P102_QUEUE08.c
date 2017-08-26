#include<stdio.h>
int queue0[100],queue1[100],queue2[100],front0=-1,rear0=-1,front1=-1,rear1=-1,front2=-1,rear2=-1;
int sum=0;
int tmparr[100],k=0;
void enqueue0(int data)
{
	if(front0==-1&&rear0==-1)
	{
		front0=rear0=0;
		queue0[rear0]=data;
	}
	else
	queue0[++rear0]=data;
}
void enqueue1(int data)
{
	if(front1==-1&&rear1==-1)
	{
		front1=rear1=0;
		queue1[rear1]=data;
	}
	else
	queue1[++rear1]=data;
}
void enqueue2(int data)
{
	if(front2==-1&&rear2==-1)
	{
		front2=rear2=0;
		queue2[rear2]=data;
	}
	else
	queue2[++rear2]=data;
}

void dequeue0()
{
    front0=front0+1;
}

void dequeue1()
{
    front1=front1+1;
}

void dequeue2()
{
    front2=front2+1;
}

void stacksort0(int queue0[],int s,int e)
{
    int mid;
    int pivot;
    if(s>e)
      return;
     else
     {
        int i,temp;
        int piv=queue0[e];
         int index=s;
          for(i=s;i<e;i++)
           {
             if(queue0[i]<=piv)
            {
            temp=queue0[i];
            queue0[i]=queue0[index];
            queue0[index]=temp;
            index++;
            }
    }

            temp=queue0[index];
            queue0[index]=queue0[e];
            queue0[e]=temp;
        mid=index;
        stacksort0(queue0,s,mid-1);
        stacksort0(queue0,mid+1,e);

}
}
void stacksort1(int queue1[],int s,int e)
{
    int mid;
    int pivot;
    if(s>e)
      return;
     else
     {
        int i,temp;
        int piv=queue1[e];
         int index=s;
          for(i=s;i<e;i++)
           {
             if(queue1[i]<=piv)
            {
            temp=queue1[i];
            queue1[i]=queue1[index];
            queue1[index]=temp;
            index++;
            }
    }

            temp=queue1[index];
            queue1[index]=queue1[e];
            queue1[e]=temp;
        mid=index;
        stacksort1(queue1,s,mid-1);
        stacksort1(queue1,mid+1,e);

}
}
void stacksort2(int queue2[],int s,int e)
{
    int mid;
    int pivot;
    if(s>e)
      return;
     else
     {
        int i,temp;
        int piv=queue2[e];
         int index=s;
          for(i=s;i<e;i++)
           {
             if(queue2[i]<=piv)
            {
            temp=queue2[i];
            queue2[i]=queue2[index];
            queue2[index]=temp;
            index++;
            }
    }

            temp=queue2[index];
            queue2[index]=queue2[e];
            queue2[e]=temp;
        mid=index;
        stacksort2(queue2,s,mid-1);
        stacksort2(queue2,mid+1,e);

}
}

void stacksort(int tmparr[],int s,int e)
{
    int mid;
    int pivot;
    if(s>e)
      return;
     else
     {
        int i,temp;
        int piv=tmparr[e];
         int index=s;
          for(i=s;i<e;i++)
           {
             if(tmparr[i]>=piv)
            {
            temp=tmparr[i];
            tmparr[i]=tmparr[index];
            tmparr[index]=temp;
            index++;
            }
    }

            temp=tmparr[index];
            tmparr[index]=tmparr[e];
            tmparr[e]=temp;
        mid=index;
        stacksort(tmparr,s,mid-1);
        stacksort(tmparr,mid+1,e);

}
}

void raise1()
{
    int i;
    for(i=front0;i<=rear0;i++)
    {
        tmparr[k++]=queue0[i];
    }
}
void raise2()
{
    int i;
    for(i=front1;i<=rear1;i++)
    {
        tmparr[k++]=queue1[i];
    }
}
void raise3()
{
    int i;
    for(i=front2;i<=rear2;i++)
    {
        tmparr[k++]=queue2[i];
    }
}
main()
{
    int n,i;
    printf("enter the size of the array : ");
    scanf("%d",&n);
    int arr[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
        int qu=arr[i]%3;
        switch(qu)
        {
        case 0:
            enqueue0(arr[i]);
            break;
        case 1:
            enqueue1(arr[i]);
            break;
        case 2:
            enqueue2(arr[i]);
            break;
        }
        sum=sum+arr[i];
    }
    stacksort0(queue0,front0,rear0);
    stacksort1(queue1,front1,rear1);
    stacksort2(queue2,front2,rear2);

    int res=sum%3;
    if(res==1)
    {
        dequeue1();
    }
    else if(res==2)
    {
        dequeue2();
    }
    raise1();
    raise2();
    raise3();

    stacksort(tmparr,0,k-1);
    int j,ren=0;
    for(j=0;j<k;j++)
    {

        ren=ren+tmparr[j];

    }
    if(ren%3==0)
    {
    for(j=0;j<k;j++)
    {

        printf("%d",tmparr[j]);
    }
    }
    else
    {
        printf("\nnot possible\n");
    }

}
