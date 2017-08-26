#include<stdio.h>
main()
{
int h[100] = {0};
int n;
printf("enter array size : ");
scanf("%d",&n);
int a[n],i,j;

for(i=0;i<n;i++)
  {
    scanf("%d",&a[i]);
    h[a[i]]++;
  }
for(i=0;i<n;i++)
{
    if(h[a[i]]>0)
    {
        printf("%d ",a[i]);
        h[a[i]]=0;
    }
}
}
