#include<stdio.h>
int front,rear;
	int i,n,k,j,res,qfirst[1]={0},count=0,qsec[1]={0};
int enqueue(int a,int b,int qfirst[],int qsec[])
{
	if(front==rear&&front==-1)
	{
		front=rear=0;
		qfirst[0]=a;
		qsec[0]=b;
	}
	else if(front==rear&&front==0)
	{
		qfirst[0]=qfirst[0]+a;
		qsec[0]=qsec[0]+b;
	}
	if(qfirst[0]<qsec[0])
	return 1;
	else
	return 0;
}
void main()
{
	printf("\nenter number of process :");
	scanf("%d",&n);
	int a[n],b[n];
	for(i=0;i<n;i++)
	{
		scanf("%d%d",&a[i],&b[i]);
	}
	for(i=0;i<n;i++)
	{
		k=0,res=0;
		for(j=i;k<n;j++)
		{
			if(j>=n)
			j=j-n;
			if(res==0)
			{
			res=enqueue(a[j],b[j],qfirst,qsec);
			}
			else
			{
			front=rear=-1;
			break;
			}
			k++;
		}
		if(count>0)
		break;
		if(res==0)
		{
		printf("We can Start from %dth index\n",i);
		count++;
		}
	}
}



