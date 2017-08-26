#include<stdio.h>
#include<string.h>
main()
{
int n,res=0;
printf("enter array size : ");
scanf("%d",&n);
int a[n],i,j;
printf("enter array elements : \n");
for(i=0;i<n;i++)
  scanf("%d",&a[i]);
for(i=0;i<n;i++)
  {
    res=0;
    for(j=i+1;j<n;j++)
     {
       if(a[i]<a[j])
          {
            res=1;
            break;
          }
     }
     if(res==0)
       printf("%d ",a[i]);
  }
}
