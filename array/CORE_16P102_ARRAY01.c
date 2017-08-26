#include<stdio.h>
int main()
{
int n;
printf("\nenter size : ");
scanf("%d",&n);
int arr[n],i,x;
for(i=0;i<n;i++)
{
    arr[i]=0;
}
for(i=0;i<n;i++)
{
scanf("%d",&x);
arr[x]++;
}
for(i=0;i<n;i++)
{
if(arr[i]>1)
{
printf("%d ",i);
}
}
return 0;
}
