#include<stdio.h>
#include<stdlib.h>

int s[10],q[10],top=-1,front=-1,rear=-1;
int a[20][20],b[20][20];
int visited[10],visited1[10],n,n2;

int push(int data)
{
    s[++top]=data;
}

int pop()
{
int ele=s[top--];
return ele;
}

int enqueue(int data)
{
    if(rear==-1&&front==-1)
    {
        front=0;
        rear=0;
        q[rear]=data;
    }
    else
        q[++rear]=data;
}

int dequeue()
{
    int ele;
    if(front==rear)
    {
        ele=q[front];
        front=-1;
        rear=-1;
    }
    else
    {
     ele=q[front++];
    }
    return ele;
}

void dfs()
{
    int i;
    for(i=0;i<n;i++)
    {
        visited[i]=0;
    }
    for(i=0;i<n;i++)
    {
        if(!visited[i])
            dfshelper(i);
    }
}

void dfshelper(int start)
{
    int ele,i,j;
    visited[start]=1;
    push(start);
    while(top!=-1)
    {
        ele=pop();
        printf("%d",ele);
    for(j=0;j<n;j++)
    {
        if(a[ele][j]!=0&&visited[j]==0)
        {
            visited[j]=1;
            push(j);
        }
    }
    }
}

void bfs()
{
    int i;
    for(i=0;i<n;i++)
    {
        visited1[i]=0;
    }
    for(i=0;i<n;i++)
    {
        if(!visited1[i])
            bfshelper(i);
    }
}

void bfshelper(int start)
{
    int ele,i,j;
    visited1[start]=1;
    enqueue(start);
    while(front!=-1)
    {
        ele=dequeue();
        printf("%d",ele);
    for(j=0;j<n;j++)
    {
        if(a[ele][j]!=0&&visited1[j]==0)
        {
            visited1[j]=1;
            enqueue(j);
        }
    }
    }
}

void readgraph()
{
    int i,j;
    printf("enter no of vertices \n");
    scanf("%d",&n);
    printf("enter the adjacency matrix\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
}

void main()
{
    int choice;
readgraph();
while(1)
{
printf("\n1.dfs\n2.bfs\n");
scanf("%d",&choice);
if(choice==1)
{
    dfs();
}
else if(choice==2)
{
    bfs();
}
}
}
